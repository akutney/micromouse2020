function [out] = pi_motor_controller(v, vn, idx)
%
% function [out] = pi_motor_controller(v, vn)
% 
% Inputs:
%   - v: mesured velocity for motor in rad/sec, positive values are clockwise
%   - vn: desired velocity for motor in rad/sec, positive values are clockwise
%   - idx: motor index
%
% Output:
%   - out: value from -1.0 to 1.0 for motor, positive values are clockwise
%
% Depends on global Ei = zeros(4,1) for first call

% Parameters
Kp = 0.04;
Ki = 0.01;
I_BOUND = 100000000;
global Ei;

% Calculate error
Ep = vn - v;
Ei(idx) = Ei(idx) + Ep;

% Bound integral error
Ei(idx) = bound(Ei(idx), -I_BOUND, I_BOUND);

out = (Kp * Ep) + (Ki * Ei(idx));

% Bound output
out = bound(out, -1, 1);

end
