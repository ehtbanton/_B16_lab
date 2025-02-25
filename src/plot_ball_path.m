data = readmatrix('ball.txt'); % load ball.txt didn't work for me

plot(data(:,1), data(:,2))
title('Ball Path')
xlabel('X Position')
ylabel('Y Position')
grid on

