///spriter_render_instance()
spriter_RenderInstance(modelIndex, instanceIndex);

var nSpriteInfos = spriter_get_instance_sprite_count();

draw_set_alpha_test(false);

//sprite info types
//IMAGE = 1, BOX = 2, POINT = 3, BONE = 4
for (i = 0; i < nSpriteInfos; i++)
{
    var sprite = spriter_GetSpriteInfoSpriteIndex(modelIndex, instanceIndex, i);
    var scaleX = spriter_GetSpriteInfoScaleX(modelIndex, instanceIndex, i);
    var scaleY = spriter_GetSpriteInfoScaleY(modelIndex, instanceIndex, i);
    var sizeX = 0;
    var sizeY = 0;
    var angle = spriter_GetSpriteInfoAngle(modelIndex, instanceIndex, i);
    var alpha = spriter_GetSpriteInfoAlpha(modelIndex, instanceIndex, i);
    var isAtlas = spriter_IsSpriteInfoAtlasFile(modelIndex, instanceIndex, i);
    
    if sprite != -1
    {
        var framePositionX = 0.0;
        var framePositionY = 0.0;
        var frameRotated = false;
        var srcImageWidth = sprite_get_width(sprite);
        var srcImageHeight = sprite_get_height(sprite);
        var frameSizeX = 0;
        var frameSizeY = 0;
        
        var texture = sprite_get_texture(sprite, -1);
        
        var texelWidth = texture_get_texel_width(texture);
        var texelHeight = texture_get_texel_height(texture);
        
        if isAtlas
        {
            framePositionX = spriter_GetSpriteInfoAtlasFramePositionX(modelIndex, instanceIndex, i);
            framePositionY = spriter_GetSpriteInfoAtlasFramePositionY(modelIndex, instanceIndex, i); 
            frameRotated = spriter_IsSpriteInfoAtlasFrameRotated(modelIndex, instanceIndex, i);
            frameSizeX = spriter_GetSpriteInfoAtlasFrameFrameSizeX(modelIndex, instanceIndex, i);
            frameSizeY = spriter_GetSpriteInfoAtlasFrameFrameSizeY(modelIndex, instanceIndex, i);
            srcImageWidth = frameSizeX;
            srcImageHeight = frameSizeY;
        }
        
        sizeX = srcImageWidth * abs(scaleX);
        sizeY = srcImageHeight * abs(scaleY);
        
        var pivotOffsetX = -sizeX * 0.5;
        var pivotOffsetY = -sizeY * 0.5;
        
        angle = -angle;
        
        spriter_SetSpriteInfoImageWidth(modelIndex, instanceIndex, i, srcImageWidth);
        spriter_SetSpriteInfoImageHeight(modelIndex, instanceIndex, i, srcImageHeight);
    
        var _x = spriter_GetSpriteInfoGMRenderPositionX(modelIndex, instanceIndex, i);
        var _y =  spriter_GetSpriteInfoGMRenderPositionY(modelIndex, instanceIndex, i);
            
        var m = matrix_2D_identity();
         
        m = matrix_2D_orientate(m, angle);
       
        var tlx = matrix_2D_x_multiply(m, pivotOffsetX, pivotOffsetY) + _x;
        var tly = matrix_2D_y_multiply(m, pivotOffsetX, pivotOffsetY) + _y;
        
        var trx = matrix_2D_x_multiply(m, pivotOffsetX + sizeX, pivotOffsetY) + _x;
        var try = matrix_2D_y_multiply(m, pivotOffsetX + sizeX, pivotOffsetY) + _y;
        
        var tbrx = matrix_2D_x_multiply(m, pivotOffsetX + sizeX, pivotOffsetY + sizeY) + _x;
        var tbry = matrix_2D_y_multiply(m, pivotOffsetX + sizeX, pivotOffsetY + sizeY) + _y;
         
        var tblx = matrix_2D_x_multiply(m, pivotOffsetX, pivotOffsetY + sizeY) + _x;
        var tbly = matrix_2D_y_multiply(m, pivotOffsetX, pivotOffsetY + sizeY) + _y;
        
        m = 0;
        
         // Flip X?
        if scaleX < 0.0
        {
          var tmp = tlx;
          tlx = trx;
          trx = tmp;
          
          tmp = tbrx;
          tbrx = tblx;
          tblx = tmp;
          
          tmp = tly;
          tly = try;
          try = tmp;
          
          tmp = tbry;
          tbry = tbly;
          tbly = tmp;
        }
        
        // Flip Y?
       if scaleY < 0.0
        {
           var tmp = tlx;
           tlx = tblx;
           tblx = tmp;
           
           tmp = trx;
           trx = tbrx;
           tbrx = tmp;
          
           tmp = tly;
           tly = tbly;
           tbly = tmp;
           
           tmp = try;
           try = tbry;
           tbry = tmp;
        }
        
        var texLeft = framePositionX * texelWidth - 0.001;
        var texRight = (framePositionX + srcImageWidth) * texelWidth;
        var texTop = framePositionY * texelHeight;
        var texBottom =  (framePositionY + srcImageHeight) * texelHeight - 0.001;
        
        var tex_m = matrix_2D_identity();
        
        if frameRotated
        {
            var sy = frameSizeY * texelHeight;
            tex_m = matrix_2D_translate(tex_m, texLeft, texTop);
            tex_m = matrix_2D_rotate(tex_m, degtorad(90));
            tex_m = matrix_2D_pretranslate(tex_m, texLeft, texTop + sy); 
        }
              
       
        var text_tlx = matrix_2D_x_multiply(tex_m, texLeft, texTop);
        var text_tly = matrix_2D_y_multiply(tex_m, texLeft, texTop);
        
        var text_trx = matrix_2D_x_multiply(tex_m, texRight, texTop);
        var text_try = matrix_2D_y_multiply(tex_m, texRight, texTop);
        
        var text_tbrx = matrix_2D_x_multiply(tex_m, texRight, texBottom);
        var text_tbry = matrix_2D_y_multiply(tex_m, texRight, texBottom);
         
        var text_tblx = matrix_2D_x_multiply(tex_m, texLeft, texBottom);
        var text_tbly = matrix_2D_y_multiply(tex_m, texLeft, texBottom);
        
        tex_m = 0;
      
        draw_set_alpha(alpha);   
        draw_set_colour(image_blend);
        draw_primitive_begin_texture(pr_trianglefan, texture);
        draw_vertex_texture(tlx, tly, text_tlx, text_tly);
        draw_vertex_texture(trx, try, text_trx, text_try);
        draw_vertex_texture(tbrx, tbry, text_tbrx, text_tbry);
        draw_vertex_texture(tblx, tbly, text_tblx, text_tbly);
        draw_primitive_end();
    }
}

draw_set_alpha_test(true);

spriter_check_errors();
