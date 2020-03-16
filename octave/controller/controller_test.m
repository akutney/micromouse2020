
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

pos = [0,0.0,0];
goal = [0.18,0.18,pi/4]';
dt = 0.001;
steps = 2000;

motion = [0,0,0,0];

for i=[1:steps]

  motor_outputs = controller(dt, pos(i,:)', goal);

  motion = [motion; motor_model(dt, motor_outputs)'];
  
  next = forward_omni_model(pos(i,:)', motion(i+1,:)');

  pos = [ pos; next' ];
  
end

pos(steps,:)
Ei

figure(1);
plot(pos(:,1));
grid;

figure(2);
plot(diff(pos(:,1)));
grid;

figure(3);
plot(pos(:,2));
grid;

figure(4);
plot(diff(pos(:,2)));
grid;

figure(5);
plot(pos(:,3));
grid;

figure(6);
plot(diff(pos(:,3)));
grid;

figure(7);
plot(pos(:,1), pos(:,2));
grid;
