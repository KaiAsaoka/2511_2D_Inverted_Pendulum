function pendan2D(block, varargin)
% PENDAN2D S-function for making 2D pendulum animation.
% Adapted to allow pendulum movement in both x and y axes.
%   See also: PENDDEMO.

% Plots every major integration step, but has no states of its own
    if nargin == 1
        setup(block);
    else
        switch varargin{end}
            %%%%%%%%%%%%%%%
            % DeleteBlock %
            %%%%%%%%%%%%%%%
            case 'DeleteBlock',
                LocalDeleteBlock
            
            %%%%%%%%%%%%%%%
            % DeleteFigure %
            %%%%%%%%%%%%%%%
            case 'DeleteFigure',
                LocalDeleteFigure
            
            %%%%%%%%%%
            % Slider %
            %%%%%%%%%%
            case 'Slider',
                LocalSlider
            
            %%%%%%%%%
            % Close %
            %%%%%%%%%
            case 'Close',
                LocalClose
            
            %%%%%%%%%%%%
            % Playback %
            %%%%%%%%%%%%
            case 'Playback',
                LocalPlayback
        end
    end
end

function setup(block)
    % Register parameters
    block.NumDialogPrms = 1; % RefBlock
    
    % Register number of ports
    block.NumInputPorts = 1;
    block.NumOutputPorts = 0;

    % Override input port properties
    block.InputPort(1).DatatypeID = 0;
    block.InputPort(1).Dimensions = 4; % [x, y, theta_x, theta_y]
    block.InputPort(1).DirectFeedthrough = true;

    % Animation is updated every 0.1 seconds
    block.SampleTimes = [0.1 0];

    % Create the figure, if necessary
    LocalPendInit(block.DialogPrm(1).Data); % RefBlock
    
    block.SimStateCompliance = 'DefaultSimState';

    block.RegBlockMethod('Update', @mdlUpdate);
    block.RegBlockMethod('Terminate', @mdlTerminate);
end

function mdlUpdate(block)
    t = block.CurrentTime;
    u = block.InputPort(1).Data;

    fig = get_param(gcbh,'UserData');
    if ishghandle(fig, 'figure'),
      if strcmp(get(fig,'Visible'),'on'),
        ud = get(fig,'UserData');
        LocalPendSets(t, ud, u);
      end
    end
end

function mdlTerminate(block)
    fig = get_param(gcbh,'UserData');
    if ishghandle(fig, 'figure')
        pushButtonPlayback = findobj(fig,'Tag','penddemoPushButton');
        set(pushButtonPlayback,'Enable','on');
    end
end

function LocalDeleteBlock
    fig = get_param(gcbh,'UserData');
    if ishghandle(fig, 'figure')
      delete(fig);
      set_param(gcbh,'UserData',-1)
    end
end

function LocalDeleteFigure
    ud = get(gcbf,'UserData');
    set_param(ud.Block,'UserData',-1);
end

function LocalSlider
    ud = get(gcbf,'UserData');
    set_param(ud.RefBlock,'Value',num2str(get(gcbo,'Value')));
end

function LocalClose
    delete(gcbf)
end

function LocalPlayback
    t = evalin('base','t','[]');
    y = evalin('base','y','[]');
    
    if isempty(t) || isempty(y),
      errordlg(...
        ['You must first run the simulation before '...
         'playing back the animation.'],...
        'Animation Playback Error');
    end
    
    try
      ud = get(gcbf,'UserData');
      for i=1:length(t),
        LocalPendSets(t(i),ud,y(i,:));
      end
    catch
    end
end

function LocalPendSets(time, ud, u)
    XCart = u(1);
    YCart = u(2);
    ThetaX = u(3);
    ThetaY = u(4);

    % Pendulum top position based on angles
    XPendTop = XCart + 10 * sin(ThetaX);
    YPendTop = YCart + 10 * cos(ThetaY);

    % Update cart and pendulum position
    set(ud.Cart, 'XData', ones(2,1)*[XCart-2 XCart+2], 'YData', ones(2,1)*[YCart YCart-2]);
    set(ud.Pend, 'XData', [XPendTop XCart], 'YData', [YPendTop YCart]);
    set(ud.TimeField, 'String', num2str(time));
    drawnow
end

function LocalPendInit(RefBlock)
    sys = get_param(gcs,'Parent');
    TimeClock = 0;
    RefSignal = str2double(get_param([sys '/' RefBlock],'Value'));
    XCart = 0;
    YCart = 0;
    ThetaX = 0;
    ThetaY = 0;

    XPendTop = XCart + 10 * sin(ThetaX);
    YPendTop = YCart + 10 * cos(ThetaY);

    Fig = get_param(gcbh,'UserData');
    if ishghandle(Fig, 'figure'),
      FigUD = get(Fig,'UserData');
      set(FigUD.TimeField, 'String', num2str(TimeClock));
      set(FigUD.Cart, 'XData', ones(2,1)*[XCart-2 XCart+2], 'YData', ones(2,1)*[YCart YCart-2]);
      set(FigUD.Pend, 'XData', [XPendTop XCart], 'YData', [YPendTop YCart]);
      set(findobj(Fig, 'Tag', 'penddemoPushButton'), 'Enable', 'off');
      figure(Fig);
      return
    end

    Fig = figure('Units','pixel','Position',[100 100 500 500],'Name','Pendulum Animation','NumberTitle','off','IntegerHandle','off','HandleVisibility','callback','Resize','off','DeleteFcn','pendan2D([],[],[],''DeleteFigure'')','CloseRequestFcn','pendan2D([],[],[],''Close'');');
    AxesH = axes('Parent', Fig, 'Units', 'pixel', 'Position', [50 50 400 400], 'XLim', [-12 12], 'YLim', [-12 12], 'Visible', 'on');
    Cart = surface('Parent', AxesH, 'XData', ones(2,1)*[XCart-2 XCart+2], 'YData', ones(2,1)*[YCart YCart-2], 'ZData', zeros(2), 'CData', 11*ones(2));
    Pend = line('Parent', AxesH, 'XData', [XPendTop XCart], 'YData', [YPendTop YCart], 'LineWidth', 2, 'Color', 'b');
    TimeField = uicontrol('Parent', Fig, 'Style', 'text', 'Units', 'pixel', 'Position', [200 0 100 25], 'String', num2str(TimeClock));
    FigUD.Cart = Cart;
    FigUD.Pend = Pend;
    FigUD.TimeField = TimeField;
    FigUD.Block = get_param(gcbh,'Handle');
    FigUD.RefBlock = get_param([sys '/' RefBlock],'Handle');
    set(Fig, 'UserData', FigUD);
    drawnow
    set_param(gcbh, 'UserData', Fig);
end
