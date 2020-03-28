
% F, L, B, R
old_pos = [0,0,0]';
new_pos = [2,0,pi]';

motion = inverse_omni_model(old_pos, new_pos)

forward_pos = forward_omni_model(old_pos, motion);

error_ = [0;0;0];
error_(1:2) = forward_pos(1:2) - new_pos(1:2);
error_(3) = forward_pos(3) - new_pos(3);
error_(3) = bound_radians_npi_to_pi(error_(3));

error_
