///spriter_update_instance()
var elapsedTime =  current_time - startTime;

spriter_set_instance_angle(degtorad(spriter_angle));

spriter_set_instance_scale(image_xscale, image_yscale);

spriter_set_instance_position(x + sprite_width * 0.5, y + sprite_height * 0.5);

spriter_UpdateInstance(modelIndex, instanceIndex, elapsedTime);

spriter_render_instance();

var nSpriteInfos = spriter_get_instance_sprite_count();

var nTriggerCount = spriter_instance_get_trigger_count();
var nSoundCount = spriter_instance_get_sound_count();

for (i = nTriggerCount - 1; i >= 0; i--)
{
    var triggerName = spriter_instance_get_trigger_name(i);
    spriter_trigger_callback(self, triggerName);
}

for (i = nSoundCount - 1; i >= 0; i--)
{
    var soundName = spriter_instance_get_sound_name(i);
    spriter_sound_callback(self, soundName);
}

//sprite info types
//IMAGE = 1, BOX = 2, POINT = 3, BONE = 4

for (i = nSpriteInfos - 1; i >= 0; i--)
{
    var sprite = spriter_GetSpriteInfoSpriteIndex(modelIndex, instanceIndex, i);
    var type = spriter_get_instance_sprite_type(i);
    var px = spriter_get_instance_sprite_xposition(i);
    var py = spriter_get_instance_sprite_yposition(i);
    var pivotX = spriter_get_instance_sprite_xpivot(i);
    var pivotY =  spriter_get_instance_sprite_ypivot(i);
    var scaleX = spriter_get_instance_sprite_xscale(i);
    var scaleY = spriter_get_instance_sprite_yscale(i);
    var sizeX = spriter_get_instance_sprite_xsize(i);
    var sizeY = spriter_get_instance_sprite_ysize(i);
    var angle = spriter_get_instance_sprite_angle(i);
    var isRender = spriter_get_instance_sprite_visible(i);
    var alpha = spriter_get_instance_sprite_alpha(i);
    var isAtlas = spriter_IsSpriteInfoAtlasFile(modelIndex, instanceIndex, i);
    
    if type == 1
    {
        inst[i].sprite_index = sprite;
    }
    
    inst[i].visible = isRender;
         
    inst[i].image_xscale = scaleX;
    inst[i].image_yscale = scaleY;
    inst[i].image_angle = radtodeg(angle);
    inst[i].image_alpha = alpha;
    inst[i].nSpriteInfo = i;
        
    spriter_set_instance_sprite_width(i, inst[i].sprite_width / scaleX);
    spriter_set_instance_sprite_height(i, inst[i].sprite_height / scaleY);
    
    var inst_x = spriter_get_instance_sprite_render_xposition(i);
    var inst_y =  spriter_get_instance_sprite_render_yposition(i);
        
    inst[i].x = inst_x;
    inst[i].y = inst_y;
    
    if type == 2
    {
        var rectWidth = sizeX * scaleX;
        var rectHeight = sizeY * scaleY;
        var dx = px - inst_x + inst_x;
        var dy = -1.0 * py - inst_y + inst_y;
        
        inst[i].x1 = dx - rectWidth;
        inst[i].y1 = dy - rectHeight * 0.5;
        inst[i].x2 = dx;
        inst[i].y2 = dy + rectHeight * 0.5;
    }
    
    if isAtlas 
    {
        var framePositionX = spriter_GetSpriteInfoAtlasFramePositionX(modelIndex, instanceIndex, i);
        var framePositionY = spriter_GetSpriteInfoAtlasFramePositionY(modelIndex, instanceIndex, i);
        var frameRotated = spriter_IsSpriteInfoAtlasFrameRotated(modelIndex, instanceIndex, i);
        var frameTrimmed = spriter_IsSpriteInfoAtlasFrameTrimmed(modelIndex, instanceIndex, i);
        var frameSizeX = spriter_GetSpriteInfoAtlasFrameFrameSizeX(modelIndex, instanceIndex, i);
        var frameSizeY = spriter_GetSpriteInfoAtlasFrameFrameSizeY(modelIndex, instanceIndex, i);
        var frameSourceSizeX = spriter_GetSpriteInfoAtlasFrameSourceSizeX(modelIndex, instanceIndex, i);
        var frameSourceSizeY = spriter_GetSpriteInfoAtlasFrameSourceSizeY(modelIndex, instanceIndex, i);
        var frameSpriteSourcePositionX = spriter_GetSpriteInfoAtlasFrameSpriteSourcePositionX(modelIndex, instanceIndex, i);
        var frameSpriteSourcePositionY = spriter_GetSpriteInfoAtlasFrameSpriteSourcePositionY(modelIndex, instanceIndex, i);
        var frameSpriteSourceSizeX = spriter_GetSpriteInfoAtlasFrameSpriteSourceSizeX(modelIndex, instanceIndex, i);
        var frameSpriteSourceSizeY = spriter_GetSpriteInfoAtlasFrameSpriteSourceSizeY(modelIndex, instanceIndex, i);
    }
    
    if sprite != -1
    {
        sprite_set_offset(sprite, inst[i].sprite_width / scaleX * 0.5, inst[i].sprite_height / scaleY * 0.5);
    }
}

startTime = current_time;

spriter_check_errors();
