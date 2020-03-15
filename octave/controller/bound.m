function [out] = bound(val, lower_, upper_)
%
% function [out] = bound(val, lower_, upper_)
% 
% Inputs:
%   - val: value to bound
%   - lower_: lower bound
%   - upper_: upper bound
%
% Output:
%   - out: bounded val

out = val;

% Bound output
if out > upper_
  out = upper_;
end

if out < lower_
  out = lower_;
end

end
