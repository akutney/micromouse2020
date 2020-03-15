function [out] = pi_motor_controller(v, vn)
%
% function [out] = pi_motor_controller(v, vn)
% 
% Inputs:
%   - v: mesured velocity for motor in radians/sec, positive values are clockwise
%   - vn: desired velocity for motor in radians/sec, positive values are clockwise
%
% Output:
%   - out: value from -1.0 to 1.0 for motor, positive values are clockwise
%
% Depends on Ei = 0 for first call

% Parameters
Kp = 1.0;
Ki = 0.1;
I_BOUND = 1.0;

% Calculate error
Ep = vn - v;
Ei = Ei + Ep;

% Bound integral error
Ei = bound(Ei, -I_BOUND, I_BOUND)

out = (Kp * Ep) + (Ki * Ei);

% Bound output
out = bound(out, -1, 1)

end
