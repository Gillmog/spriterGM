//matrix_2D_orientate(matrix, angle)
var _angle = argument1;
var c = cos(_angle);
var s = sin(_angle);

argument0[0] = c; 
argument0[1] = -s; 
argument0[2] = 0.0;
argument0[3] = s;
argument0[4] =  c; 
argument0[5] = 0.0;

return argument0;




