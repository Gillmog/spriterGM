///spriter_get_point_y2(object, point_index)
var angle = -1.0 * spriter_GetObjectInfoAngle(argument0.modelIndex, argument0.instanceIndex, argument1);
var py = spriter_GetObjectInfoGMRenderPositionY(argument0.modelIndex, argument0.instanceIndex, argument1);
spriter_check_errors();
return py + sin(angle) * 6;
