
addpath("C:/Users/Dylan Staatz/Documents/code/github/robotics/micromouse2020/octave")
addpath("C:/Users/Dylan Staatz/Documents/code/github/robotics/micromouse2020/octave/controller")
addpath("C:/Users/Dylan Staatz/Documents/code/github/robotics/micromouse2020/octave/omni_model")
addpath("C:/Users/Dylan Staatz/Documents/code/github/robotics/micromouse2020/octave/utility")

clear

global MAX_MOTOR_SPEED;
MAX_MOTOR_SPEED = 10*pi; % (rad/sec)
global Ei;
Ei = zeros(4,1);
global prev_x;
prev_x = zeros(3,1);

pos = [0,0,0];
goal = [0.18,0.18,0]';
dt = 0.001;
steps = 5000;

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
plot(pos(:,1));
grid;

figure(2);
hold on;
plot(diff(pos(:,1)), 'b');
plot(movmean(diff(pos(:,1)),50), 'r');
hold off;
grid;

figure(3);
plot(pos(:,2));
grid;

figure(4);
hold on;
plot(diff(pos(:,2)), 'b');
plot(movmean(diff(pos(:,2)),50), 'r');
hold off;
grid;

figure(5);
plot(pos(:,3));
grid;

figure(6);
hold on;
plot(diff(pos(:,3)), 'b');
plot(movmean(diff(pos(:,3)),50), 'r');
hold off;
grid;

figure(7);
plot(pos(:,1), pos(:,2));
grid;
