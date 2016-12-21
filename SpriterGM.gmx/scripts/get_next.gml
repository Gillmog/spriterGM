//get_next(number)
var num = argument0;

var one  = 0;
var shift = -1;

while (num) 
{
   if num & 1
   one++;
         
  shift++;
  num = num >> 1;
}
   
if one > 1
  shift++;

return 1 << shift;

