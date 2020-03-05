
% F, L, B, R
inputs = [
  0, -1, 0, 1; % forward 1
  1, 0, -1, 0; % left 1
  0, 1, 0, -1; % back 1
  -1, 0, 1, 0; % right 1
];

output_pos = [0,0,0];

for i = 1:size(inputs)(1)
  output_pos = [output_pos; omni_model(output_pos(i,:).', inputs(i,:)).' ];
  plot(output_pos(:,1), output_pos(:,2));
  pause
end
