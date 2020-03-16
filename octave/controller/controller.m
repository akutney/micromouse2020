function [out] = controller(dt, x, xn)
%
% function [out] = controller(dt, x, xn)
% 
% Inputs:
%   - dt: time in seconds since last call
%   - x: mesured state of robot
%       1:  x
%       2:  y
%       3:  theta
%   - xn: desired state of robot
%       1:  x
%       2:  y
%       3:  theta
%
% Output:
%   - out: value from -1.0 to 1.0 for motor, positive values are clockwise
%       1: MOTOR_F
%       2: MOTOR_L
%       3: MOTOR_B
%       4: MOTOR_R

% Parameters
global prev_x;
global MAX_MOTOR_SPEED;

prev_motion = inverse_omni_model(prev_x, x);      % "Measured" distance travelled by each wheel
prev_wheels = wheel_m_to_rad(prev_motion) ./ dt; % "Measured" Wheel speed (rad/sec) (only for simulation)

next_motion = inverse_omni_model(x, xn);          % Desired distance to travel by each wheel in total (gives us a ratio to work with)

% map to -1 and 1
bound = max(abs(next_motion));
next_ratio = mapfun(next_motion, -1*bound, bound, -1, 1);

next_wheels = next_ratio .* MAX_MOTOR_SPEED; % TODO: multiply by a limiter to slow down?

out = zeros(3,1);
for i=[1:4]
  out(i) = pi_motor_controller(prev_wheels(i), next_wheels(i), i);
end

prev_x = x;

end
