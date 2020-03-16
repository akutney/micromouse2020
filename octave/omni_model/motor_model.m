function [motion] = motor_model(dt, pwm)
%
% function [motion] = motor_model(dt, pwm)
% 
% Inputs:
%   - dt: time in seconds
%   - pwm: Values from -1.0 to 1.0 of the pwm duty cycle
%       1: MOTOR_F
%       2: MOTOR_L
%       3: MOTOR_B
%       4: MOTOR_R
%
% Output:
%   - motion: distances traveled by each wheel
%       1: MOTOR_F
%       2: MOTOR_L
%       3: MOTOR_B
%       4: MOTOR_R

global MAX_MOTOR_SPEED;

% Uncomment to add in random error
e = mapfun(rand(4,1), 0,1, -0.5, 0.5);
pwm = pwm + e;

motion = wheel_rad_to_m(pwm .* MAX_MOTOR_SPEED .* dt);

end
