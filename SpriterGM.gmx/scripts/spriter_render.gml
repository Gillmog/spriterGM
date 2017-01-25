///spriter_render(object, debug_draw)
var modelIndex = argument0.modelIndex;
var instanceIndex = argument0.instanceIndex;
var blend = argument0.image_blend;
var nObjectInfos = spriter_GetObjectInfoCount(modelIndex, instanceIndex);
draw_set_alpha_test(false);
var currentSprite = -1;
var currentTexture = -1;
var debug_draw = argument1;
for (i = 0; i < nObjectInfos; i++)
{
    var sprite = spriter_GetObjectInfoSpriteIndex(modelIndex, instanceIndex, i);
    if sprite != -1
    {
        if currentSprite != sprite
        {
            currentTexture = sprite_get_texture(sprite, -1);
            currentSprite = sprite;
        }
        var alpha = spriter_GetObjectInfoAlpha(modelIndex, instanceIndex, i);
        var tlx = spriter_GetObjectInfoMeshPointX(modelIndex, instanceIndex, i, 0);
        var tly = spriter_GetObjectInfoMeshPointY(modelIndex, instanceIndex, i, 0);
        var trx = spriter_GetObjectInfoMeshPointX(modelIndex, instanceIndex, i, 1);
        var try = spriter_GetObjectInfoMeshPointY(modelIndex, instanceIndex, i, 1);
        var tbrx = spriter_GetObjectInfoMeshPointX(modelIndex, instanceIndex, i, 2);
        var tbry = spriter_GetObjectInfoMeshPointY(modelIndex, instanceIndex, i, 2);
        var tblx = spriter_GetObjectInfoMeshPointX(modelIndex, instanceIndex, i, 3);
        var tbly = spriter_GetObjectInfoMeshPointY(modelIndex, instanceIndex, i, 3);
        var text_tlx = spriter_GetObjectInfoMeshUVX(modelIndex, instanceIndex, i, 0);
        var text_tly = spriter_GetObjectInfoMeshUVY(modelIndex, instanceIndex, i, 0);
        var text_trx = spriter_GetObjectInfoMeshUVX(modelIndex, instanceIndex, i, 1);
        var text_try = spriter_GetObjectInfoMeshUVY(modelIndex, instanceIndex, i, 1);
        var text_tbrx = spriter_GetObjectInfoMeshUVX(modelIndex, instanceIndex, i, 2);
        var text_tbry = spriter_GetObjectInfoMeshUVY(modelIndex, instanceIndex, i, 2);
        var text_tblx = spriter_GetObjectInfoMeshUVX(modelIndex, instanceIndex, i, 3);
        var text_tbly = spriter_GetObjectInfoMeshUVY(modelIndex, instanceIndex, i, 3);
        draw_set_alpha(alpha * image_alpha);   
        draw_set_colour(blend);
        draw_primitive_begin_texture(pr_trianglelist, currentTexture);
        draw_vertex_texture(tlx, tly, text_tlx, text_tly);
        draw_vertex_texture(trx, try, text_trx, text_try);
        draw_vertex_texture(tblx, tbly, text_tblx, text_tbly);
        draw_vertex_texture(tbrx, tbry, text_tbrx, text_tbry);
        draw_vertex_texture(trx, try, text_trx, text_try);
        draw_vertex_texture(tblx, tbly, text_tblx, text_tbly);
        draw_primitive_end();
    }
    else
    if debug_draw
    {
        var type = spriter_GetObjectInfoType(modelIndex, instanceIndex, i);
        var alpha = spriter_GetObjectInfoAlpha(modelIndex, instanceIndex, i);
        //BOX
        if type == 2 
        {
            var tlx = spriter_GetObjectInfoMeshPointX(modelIndex, instanceIndex, i, 0);
            var tly = spriter_GetObjectInfoMeshPointY(modelIndex, instanceIndex, i, 0);
            var trx = spriter_GetObjectInfoMeshPointX(modelIndex, instanceIndex, i, 1);
            var try = spriter_GetObjectInfoMeshPointY(modelIndex, instanceIndex, i, 1);
            var tbrx = spriter_GetObjectInfoMeshPointX(modelIndex, instanceIndex, i, 2);
            var tbry = spriter_GetObjectInfoMeshPointY(modelIndex, instanceIndex, i, 2);
            var tblx = spriter_GetObjectInfoMeshPointX(modelIndex, instanceIndex, i, 3);
            var tbly = spriter_GetObjectInfoMeshPointY(modelIndex, instanceIndex, i, 3);
            draw_set_alpha(alpha * image_alpha); 
            draw_set_colour(blend);
            draw_line(tlx, tly, trx, try);
            draw_line(trx, try, tbrx, tbry);
            draw_line(tbrx, tbry, tblx, tbly);
            draw_line(tblx, tbly, tlx, tly);
        }
        //POINT
        if type == 3
        {
            var px = spriter_GetObjectInfoGMRenderPositionX(modelIndex, instanceIndex, i);
            var py = spriter_GetObjectInfoGMRenderPositionY(modelIndex, instanceIndex, i);
            var angle = -1.0 *spriter_GetObjectInfoAngle(modelIndex, instanceIndex, i);
            var dx = px + cos(angle) * 6;
            var dy = py + sin(angle) * 6;
            draw_set_alpha(alpha * image_alpha); 
            draw_set_colour(blend);
            draw_circle(px, py, 6, true);
            draw_line(px, py, dx, dy);
        }
        //BONE
        if type == 4
        {
            var px = spriter_GetObjectInfoPositionX(modelIndex, instanceIndex, i);
            var py = -1.0 * spriter_GetObjectInfoPositionY(modelIndex, instanceIndex, i);
            var sizex = spriter_GetObjectInfoSizeX(modelIndex, instanceIndex, i);
            var sizey = spriter_GetObjectInfoSizeY(modelIndex, instanceIndex, i);
            var sx = spriter_GetObjectInfoScaleX(modelIndex, instanceIndex, i);
            var sy = spriter_GetObjectInfoScaleY(modelIndex, instanceIndex, i);
            var angle = -1.0 * spriter_GetObjectInfoAngle(modelIndex, instanceIndex, i);
            
            if sx * sy < 0
            {
                angle *= -1.0;
            }
            
            var dx = px + cos(angle) * (sizex) * sx;
            var dy = py + sin(angle) * (sizex) * sy;
            draw_set_alpha(alpha * image_alpha); 
            draw_set_colour(blend);
            draw_line(px, py, dx, dy);
            var dx1 = px + cos(angle + degtorad(45)) * (sizey * 0.5) * sx;
            var dy1 = py + sin(angle + degtorad(45)) * (sizey * 0.5 * sy);
            draw_line(px, py, dx1, dy1);
            var dx2 = px + cos(angle + degtorad(-45)) * (sizey * 0.5) * sx;
            var dy2 = py + sin(angle + degtorad(-45)) * (sizey * 0.5) * sy;
            draw_line(px, py, dx2, dy2);
            draw_line(dx1, dy1, dx, dy);
            draw_line(dx2, dy2, dx, dy);
        }
    }
}
draw_set_alpha_test(true);
spriter_check_errors();
