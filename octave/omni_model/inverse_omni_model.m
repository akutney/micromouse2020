function [motion] = inverse_omni_model(old_pos, new_pos)
%
% function [motion] = inverse_omni_model(old_pos, new_pos)
% 
% Inputs:
%   - old_pos (m, m, radians): vector with the following values of the robots location:
%       1:  x
%       2:  y
%       3:  theta
%   - new_pos: position vector of robot after transformation
%
% Output:
%   - motion (m): vector of the distances traveled by each motor, positive values are clockwise
%       1: MOTOR_F
%       2: MOTOR_L
%       3: MOTOR_B
%       4: MOTOR_R

% Robot Parameters
d = 0.05; % 5 cm

% Calculate transform and translate to local coordinates (clockwise rotation)
theta = old_pos(3);
to_local = [ cos(theta),   sin(theta), 0;
             -sin(theta),  cos(theta), 0;
             0,            0,          1 ];
transform = to_local * (new_pos - old_pos);

% Bound transform(3) to -pi and pi so that we don't rotate more than we need to.
transform(3) = bound_radians_npi_to_pi(transform(3));

% Back solve to calculate motion vector
k = 1/(4*d);
A = [ 0,    -0.5,  0,     0.5;
      0.5,  0,     -0.5,  0;
      k,    k,     k,     k   ];

motion = A \ transform;

end
