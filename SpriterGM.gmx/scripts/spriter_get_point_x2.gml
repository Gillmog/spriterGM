//spriter_get_point_x2(object, point_index)
var angle = -1.0 * spriter_GetSpriteInfoAngle(argument0.modelIndex, argument0.instanceIndex, argument1);
var px = spriter_GetSpriteInfoGMRenderPositionX(argument0.modelIndex, argument0.instanceIndex, argument1);
spriter_check_errors();
return px + cos(angle) * 6;
