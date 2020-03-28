function [radians] = wheel_m_to_rad(meters)
%
% function [radians] = wheel_m_to_rad(meters)
% 
% Input:
%   - meters: distance in meters that the omni wheel travels
%
% Output:
%   - radians: distance in radians of a turn on the omni wheels

% Parameter (radius of omni wheel in meters)
r = 0.0381/2; % from https://www.aliexpress.com/item/32600301233.html?spm=a2g0s.9042311.0.0.32814c4ddeytOI

radians = meters ./ r;

end
