% Load the data
data = readmatrix('springmass.txt');

% Separate the data for mass1 (odd rows) and mass2 (even rows)
mass1_data = data(1:2:end, :);  % Take odd rows
mass2_data = data(2:2:end, :);  % Take even rows

% Create the plot
figure;
hold on;

% Plot mass1 trajectory in blue
plot(mass1_data(:,1), mass1_data(:,2), 'b-', 'LineWidth', 2, 'DisplayName', 'Mass 1');

% Plot mass2 trajectory in red
plot(mass2_data(:,1), mass2_data(:,2), 'r-', 'LineWidth', 2, 'DisplayName', 'Mass 2');

% Add title and labels
title('Spring-Mass System Trajectories')
xlabel('X Position')
ylabel('Y Position')
grid on
legend('show')

% Make the plot square to better show the circular motion
axis equal

% Add markers for starting positions
plot(mass1_data(1,1), mass1_data(1,2), 'bo', 'MarkerFaceColor', 'b', 'DisplayName', 'Mass 1 Start');
plot(mass2_data(1,1), mass2_data(1,2), 'ro', 'MarkerFaceColor', 'r', 'DisplayName', 'Mass 2 Start');

hold off;