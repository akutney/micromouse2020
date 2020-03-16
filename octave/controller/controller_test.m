
addpath("../omni_model")
addpath("../utility")

clear

global MAX_MOTOR_SPEED;
MAX_MOTOR_SPEED = 4*pi; % (rad/sec)
global Ei;
Ei = zeros(4,1);
global prev_x;

pos = [0,0,0];
prev_x = pos';
goal = [0.18,0.18,0]';
dt = 0.001;
steps = 2000;

motion = [0,0,0,0];

for i=[1:steps]

  motor_outputs = controller(dt, pos(i,:)', goal);

  motion = [motion; motor_model(dt, motor_outputs)'];
  
  next = forward_omni_model_error(pos(i,:)', motion(i+1,:)');

  pos = [ pos; next' ];
  
end

last = pos(steps,:)
Ei

figure(1);

subplot(2,3,1);
plot(pos(:,1));
grid;

subplot(2,3,4);
plot(diff(pos(:,1)), 'b');
hold on;
plot(movmean(diff(pos(:,1)),50), 'r');
hold off;
grid;

subplot(2,3,2);
plot(pos(:,2));
grid;

subplot(2,3,5);
plot(diff(pos(:,2)), 'b');
hold on;
plot(movmean(diff(pos(:,2)),50), 'r');
hold off;
grid;

subplot(2,3,3);
plot(pos(:,3));
grid;

subplot(2,3,6);
plot(diff(pos(:,3)), 'b');
hold on;
plot(movmean(diff(pos(:,3)),50), 'r');
hold off;
grid;

figure(2);
plot(pos(:,1), pos(:,2));
grid;
