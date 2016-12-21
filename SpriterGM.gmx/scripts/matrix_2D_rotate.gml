//matrix_2D_rotate(matrix, angle)
var c = cos(argument1);
var s = sin(argument1);

var m0 = argument0[0];
var m1 = argument0[1];
var m2 = argument0[2];
var m3 = argument0[3];
var m4 = argument0[4];
var m5 = argument0[5];

argument0[0] =  m0 * c + m1 * s;

argument0[1] = -m0 * s + m1 * c;

argument0[3] =  m3 * c + m4 * s;

argument0[4] = -m3 * s + m4 * c;

return argument0;

