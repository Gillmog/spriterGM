///spriter_load_model(file, instance_name)
var file = argument0;
var instanceName = argument1;

spriter_angle = 0.0;
spriter_xscale = 1.0;
spriter_yscale = 1.0;

spriterFile = file;
modelIndex = spriter_LoadModel(spriterFile);
spriter_check_errors();

instanceIndex = spriter_CreateInstance(modelIndex, instanceName);
spriter_check_errors();
spriter_set_instance_position(x + sprite_width * 0.5, y + sprite_height * 0.5);
spriter_set_instance_scale(1.0, 1.0);

startTime = current_time;
instCount = 0;
spriter_UpdateInstance(modelIndex, instanceIndex, 0.0);
spriter_RenderInstance(modelIndex, instanceIndex);

var nSpriteInfos = spriter_get_instance_sprite_count();

//sprite info types
//IMAGE = 1, BOX = 2, POINT = 3, BONE = 4
for (i = nSpriteInfos - 1; i >= 0; i--)
{
    var spriteName = spriter_get_instance_sprite_name(i);
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

    if type == 1
    {
        sprite[i] = sprite_add(spriteName,1,0,0,0,0);
        sprite_names[i] = spriteName;
    }
    
    if type > 1
    {
        sprite[i] = -1
    }
    
    var instanceObject = -1;
    
    switch(type)
    {
        case 1:
        instanceObject = spriterModel_image;
        break;
        case 2:
        instanceObject = spriterModel_box;
        break;
        case 3:
        instanceObject = spriterModel_point;
        break;
        case 4:
        break;
    }
    
    inst[i] = instance_create(0, 0, instanceObject);
    
    if sprite[i] != -1
    {
        inst[i].sprite_index = sprite[i];
    }
    
    inst[i].image_xscale = scaleX;
    inst[i].image_yscale = scaleY;
    inst[i].image_angle = radtodeg(angle);
    inst[i].image_alpha = alpha;
    
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
        
    if sprite[i] != -1
    {
        sprite_set_offset(sprite[i], inst[i].sprite_width / scaleX * 0.5, inst[i].sprite_height / scaleY * 0.5);
    }
        
    instCount+=1;
}

spriter_check_errors();
