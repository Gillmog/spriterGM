///spriter_render(object)
var modelIndex = argument0.modelIndex;
var instanceIndex = argument0.instanceIndex;
var blend = argument0.image_blend;

spriter_RenderInstance(modelIndex, instanceIndex);
var nSpriteInfos = spriter_GetSpriteInfoCount(modelIndex, instanceIndex);
draw_set_alpha_test(false);
for (i = 0; i < nSpriteInfos; i++)
{
    var sprite = spriter_GetSpriteInfoSpriteIndex(modelIndex, instanceIndex, i);
    if sprite != -1
    {
        var alpha = spriter_GetSpriteInfoAlpha(modelIndex, instanceIndex, i);
        var tlx = spriter_GetSpriteInfoMeshPointX(modelIndex, instanceIndex, i, 0);
        var tly = spriter_GetSpriteInfoMeshPointY(modelIndex, instanceIndex, i, 0);
        var trx = spriter_GetSpriteInfoMeshPointX(modelIndex, instanceIndex, i, 1);
        var try = spriter_GetSpriteInfoMeshPointY(modelIndex, instanceIndex, i, 1);
        var tbrx = spriter_GetSpriteInfoMeshPointX(modelIndex, instanceIndex, i, 2);
        var tbry = spriter_GetSpriteInfoMeshPointY(modelIndex, instanceIndex, i, 2);
        var tblx = spriter_GetSpriteInfoMeshPointX(modelIndex, instanceIndex, i, 3);
        var tbly = spriter_GetSpriteInfoMeshPointY(modelIndex, instanceIndex, i, 3);
        var text_tlx = spriter_GetSpriteInfoMeshUVX(modelIndex, instanceIndex, i, 0);
        var text_tly = spriter_GetSpriteInfoMeshUVY(modelIndex, instanceIndex, i, 0);
        var text_trx = spriter_GetSpriteInfoMeshUVX(modelIndex, instanceIndex, i, 1);
        var text_try = spriter_GetSpriteInfoMeshUVY(modelIndex, instanceIndex, i, 1);
        var text_tbrx = spriter_GetSpriteInfoMeshUVX(modelIndex, instanceIndex, i, 2);
        var text_tbry = spriter_GetSpriteInfoMeshUVY(modelIndex, instanceIndex, i, 2);
        var text_tblx = spriter_GetSpriteInfoMeshUVX(modelIndex, instanceIndex, i, 3);
        var text_tbly = spriter_GetSpriteInfoMeshUVY(modelIndex, instanceIndex, i, 3);
        
        draw_set_alpha(alpha * image_alpha);   
        draw_set_colour(blend);
        draw_primitive_begin_texture(pr_trianglefan, sprite_get_texture(sprite, -1));
        draw_vertex_texture(tlx, tly, text_tlx, text_tly);
        draw_vertex_texture(trx, try, text_trx, text_try);
        draw_vertex_texture(tbrx, tbry, text_tbrx, text_tbry);
        draw_vertex_texture(tblx, tbly, text_tblx, text_tbly);
        draw_primitive_end();
    }
}
draw_set_alpha_test(true);
spriter_check_errors();
