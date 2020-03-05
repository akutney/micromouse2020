function [out] = omni_model(pos, motor_motion)
%
% function [out] = omni_model(pos, motor_motion)
% 
% Inputs:
%   - pos (m, m, radians): vector with the following values of the robots location:
%       1:  x
%       2:  y
%       3:  theta
%   - motor_motion (m): vector of the distances traveled by each motor, positive values are clockwise
%       1: MOTOR_FL
%       2: MOTOR_FR
%       3: MOTOR_BR
%       4: MOTOR_BL
%
% Output:
%   - out: position vector of robot after transformation
%
% Based on this paper: https://pdfs.semanticscholar.org/c423/24ef055a86da36e78c32bfb68f15cf1fa053.pdf

% Robot Parameters
d = 0.05; % 5 cm

% First calculate the transformation along the robots axis
local = [0;0;0];
local(1) = 0.5 .* (motor_motion(4) - motor_motion(2));
local(2) = 0.5 .* (motor_motion(1) - motor_motion(3));
local(3) = (motor_motion(1) + motor_motion(2) + motor_motion(3) + motor_motion(4)) ./ (4.*d);

% Translate local coordinates to global coordinates
theta = pos(3);
transform_to_global = [ cos(theta),  -sin(theta), 0;
                        sin(theta),   cos(theta), 0;
                        0,            0,          1 ];
out = (transform_to_global * local) + pos


end