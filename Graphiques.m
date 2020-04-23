fileID = fopen('/Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie/Interface/SimOut.txt','r');
sizeData = [13 Inf];
data = fscanf(fileID, '%f %f %f %f %f %f %f %f %f %f %f %c %i', sizeData);
data=transpose(data);

mean(diff(data(:,1)))
std(diff(data(:,1)))
plot(data(1:100,1),data(1:100, 3))
