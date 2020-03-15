function [bounded] = bound_radians_npi_to_pi(theta)
%
% function [bounded] = bound_radians_npi_to_pi(theta)
%
% Input: theta: value in radians
%
% Output: bounded: bounded value in radians in range (-pi, pi]

while theta > pi
  theta = theta - 2*pi;
end

while theta <= -pi
  theta = theta + 2*pi;
end

bounded = theta;

end
