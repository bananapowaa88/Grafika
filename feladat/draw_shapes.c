#include "draw_shapes.h"

void draw_boxes(struct Box* boxes_list)
{
    struct Box* box;
    box = boxes_list->next;
    while (box->linked_list_role != HEAD) {
        glPushMatrix();
        draw_box(box);
        glPopMatrix();
        box = box->next;
    }
}

void draw_characters(struct Character* characters_list)
{
    struct Character* character;
    character = characters_list->next;
    while (character->linked_list_role != HEAD) {
        glPushMatrix();
        glTranslatef(character->pos.x,character->pos.y, character->pos.z);
        glScaled(0.15,0.15,0.15);
        glRotatef(90, 1, 0, 0);
        glRotatef(character->face, 0, 1, 0);

        draw_character(character);
        glPopMatrix();
        character = character->next;        
    }
}

void draw_box(struct Box* box)
{
  struct Point st = box->min;
  struct Point nd = box->max;
  struct Point texture_st;
  struct Point texture_nd;
  float texture_zoom = box->texture_zoom;
  double k,l;
  
    texture_st.x = 0;
    texture_st.y = 0;
    texture_st.z = 0;
    texture_nd.x = 1;
    texture_nd.y = 1;
    texture_nd.z = 1;
  
  
  // Choosing texture
  switch (box->texture)
  {
    case BRICK: glBindTexture(GL_TEXTURE_2D, box_texture.brick); break;
    case GRASS: glBindTexture(GL_TEXTURE_2D, box_texture.grass); break;
  }
  int normal_flip = -1;
  if (box->box_is_main_wall == TRUE) normal_flip = 1; 
  
  // Setting material attributes
  set_material_box();
  
  /* top */  
    int AMOUNT = 4;
    int NORMAL_SIZE = 20;
    double tex_size = 5;
    int tex_iterator_1 = 0;
    int tex_iterator_2;
    for (k = st.x; k < nd.x; k += AMOUNT)
    {
        tex_iterator_2 = 0;
        for(l = st.y; l < nd.y; l += AMOUNT)
        {
            glBegin(GL_QUADS);
            glNormal3f(k,l,NORMAL_SIZE);
            glTexCoord2f(tex_iterator_1 / tex_size, tex_iterator_2 / tex_size);
            glVertex3f(  k, l, nd.z);
            glNormal3f(k,l+AMOUNT,NORMAL_SIZE);
            glTexCoord2f(tex_iterator_1 / tex_size, (tex_iterator_2+1) / tex_size);
            glVertex3f(  k, l+AMOUNT, nd.z);
            glNormal3f(k+AMOUNT,l+AMOUNT,NORMAL_SIZE);	
            glTexCoord2f((tex_iterator_1+1) / tex_size, (tex_iterator_2+1) / tex_size);
            glVertex3f(  k+AMOUNT, l+AMOUNT, nd.z);
            glNormal3f(k+AMOUNT,l,NORMAL_SIZE);
            glTexCoord2f((tex_iterator_1+1) / tex_size, tex_iterator_2 / tex_size);
            glVertex3f(  k+AMOUNT, l, nd.z);    
            glEnd();
            tex_iterator_2++;
            if(tex_iterator_2 >= tex_size) tex_iterator_2 = 0;
         }
         tex_iterator_1++;
         if(tex_iterator_1 >= tex_size) tex_iterator_1 = 0;
    }
    tex_iterator_1 = 0;
    for (k = st.x; k < nd.x; k += AMOUNT)
    {
        tex_iterator_2 = 0;
        for(l = st.z; l < nd.z; l += AMOUNT)
        {
            glBegin(GL_QUADS);
            glNormal3f(k,-1*NORMAL_SIZE,l);
            glTexCoord2f(tex_iterator_1 / tex_size, tex_iterator_2 / tex_size);
            glVertex3f(k, st.y, l);
            glNormal3f(k+AMOUNT,-1*NORMAL_SIZE,l);
            glTexCoord2f((tex_iterator_1+1) / tex_size, tex_iterator_2 / tex_size);
            glVertex3f(k+AMOUNT, st.y, l);
            glNormal3f(k+AMOUNT,-1*NORMAL_SIZE,l+AMOUNT);	
            glTexCoord2f((tex_iterator_1+1) / tex_size, (tex_iterator_2+1) / tex_size);
            glVertex3f(  k+AMOUNT, st.y ,l+AMOUNT);
            glNormal3f(k,-1*NORMAL_SIZE,l+AMOUNT);
            glTexCoord2f(tex_iterator_1 / tex_size, (tex_iterator_2+1) / tex_size);
            glVertex3f(  k, st.y, l+AMOUNT);    
            glEnd();
            tex_iterator_2++;
            if(tex_iterator_2 >= tex_size) tex_iterator_2 = 0;
         }
         tex_iterator_1++;
         if(tex_iterator_1 >= tex_size) tex_iterator_1 = 0;
    }
    tex_iterator_1 = 0;
    for (k = st.y; k < nd.y; k += AMOUNT)
    {
        tex_iterator_2 = 0;
        for(l = st.z; l < nd.z; l += AMOUNT)
        {
            glBegin(GL_QUADS);
            glNormal3f(NORMAL_SIZE*normal_flip,k,l);
            glTexCoord2f(tex_iterator_1 / tex_size, tex_iterator_2 / tex_size);
            glVertex3f(  st.x, k, l);
            glNormal3f(NORMAL_SIZE*normal_flip,k+AMOUNT,l);
            glTexCoord2f((tex_iterator_1+1) / tex_size, tex_iterator_2 / tex_size);
            glVertex3f(  st.x, k+AMOUNT,  l);
            glNormal3f(NORMAL_SIZE*normal_flip,k+AMOUNT,l+AMOUNT);	
            glTexCoord2f((tex_iterator_1+1) / tex_size, (tex_iterator_2+1) / tex_size);
            glVertex3f(  st.x, k+AMOUNT, l+AMOUNT);
            glNormal3f(NORMAL_SIZE*normal_flip,k,l+AMOUNT);
            glTexCoord2f(tex_iterator_1 / tex_size, (tex_iterator_2+1) / tex_size);
            glVertex3f(  st.x, k, l+AMOUNT);    
            glEnd();
            tex_iterator_2++;
            if(tex_iterator_2 >= tex_size) tex_iterator_2 = 0;
         }
         tex_iterator_1++;
         if(tex_iterator_1 >= tex_size) tex_iterator_1 = 0;
    }
    tex_iterator_1 = 0;
    for (k = st.y; k < nd.y; k += AMOUNT)
    {
        tex_iterator_2 = 0;
        for(l = st.z; l < nd.z; l += AMOUNT)
        {
            glBegin(GL_QUADS);
            glNormal3f(-1*NORMAL_SIZE*normal_flip,k,l);
            glTexCoord2f(tex_iterator_1 / tex_size, tex_iterator_2 / tex_size);
            glVertex3f(  nd.x, k, l);
            glNormal3f(-1*NORMAL_SIZE*normal_flip,k+AMOUNT,l);
            glTexCoord2f((tex_iterator_1+1) / tex_size, tex_iterator_2 / tex_size);
            glVertex3f(  nd.x, k+AMOUNT,  l);
            glNormal3f(-1*NORMAL_SIZE*normal_flip,k+AMOUNT,l+AMOUNT);
            glTexCoord2f((tex_iterator_1+1) / tex_size, (tex_iterator_2+1) / tex_size);
            glVertex3f(  nd.x, k+AMOUNT, l+AMOUNT);
            glNormal3f(-1*NORMAL_SIZE*normal_flip,k,l+AMOUNT);
            glTexCoord2f(tex_iterator_1 / tex_size, (tex_iterator_2+1) / tex_size);
            glVertex3f(  nd.x, k, l+AMOUNT);    
            glEnd();
            tex_iterator_2++;
            if(tex_iterator_2 >= tex_size) tex_iterator_2 = 0;
         }
         tex_iterator_1++;
         if(tex_iterator_1 >= tex_size) tex_iterator_1 = 0;
    }
    tex_iterator_1 = 0;
    for (k = st.x; k < nd.x; k += AMOUNT)
    {
        tex_iterator_2 = 0;
        for(l = st.z; l < nd.z; l += AMOUNT)
        {
            glBegin(GL_QUADS);
            glNormal3f(k,NORMAL_SIZE,l);
            glTexCoord2f(tex_iterator_1 / tex_size, tex_iterator_2 / tex_size);
            glVertex3f(  k, nd.y, l);
            glNormal3f(k+AMOUNT,NORMAL_SIZE,l);
            glTexCoord2f((tex_iterator_1+1) / tex_size, tex_iterator_2 / tex_size);
            glVertex3f(  k+AMOUNT, nd.y, l);
            glNormal3f(k+AMOUNT,NORMAL_SIZE,l+AMOUNT);
            glTexCoord2f((tex_iterator_1+1) / tex_size, (tex_iterator_2+1) / tex_size);
            glVertex3f(  k+AMOUNT, nd.y ,l+AMOUNT);
            glNormal3f(k,NORMAL_SIZE,l+AMOUNT);
            glTexCoord2f(tex_iterator_1 / tex_size, (tex_iterator_2+1) / tex_size);
            glVertex3f(  k, nd.y, l+AMOUNT);    
            glEnd();
            tex_iterator_2++;
            if(tex_iterator_2 >= tex_size) tex_iterator_2 = 0;
         }
         tex_iterator_1++;
         if(tex_iterator_1 >= tex_size) tex_iterator_1 = 0;
    }
    tex_iterator_1 = 0;
    for (k = st.x; k < nd.x; k += AMOUNT)
    {
        tex_iterator_2 = 0;
        for(l = st.y; l < nd.y; l += AMOUNT)
        {
            glBegin(GL_QUADS);
            glNormal3f(0,0,1);
            glTexCoord2f(tex_iterator_1 / tex_size, tex_iterator_2 / tex_size);
            glVertex3f(  k, l, st.z);
            glNormal3f(0,0,1);
            glTexCoord2f(tex_iterator_1 / tex_size, (tex_iterator_2+1) / tex_size);
            glVertex3f(  k, l+AMOUNT, st.z);
            glNormal3f(0,0,1);	
            glTexCoord2f((tex_iterator_1+1) / tex_size, (tex_iterator_2+1) / tex_size);
            glVertex3f(  k+AMOUNT, l+AMOUNT, st.z);
            glNormal3f(0,0,1);
            glTexCoord2f((tex_iterator_1+1) / tex_size, tex_iterator_2 / tex_size);
            glVertex3f(  k+AMOUNT, l, st.z);    
            glEnd();
            tex_iterator_2++;
            if(tex_iterator_2 >= tex_size) tex_iterator_2 = 0;
         }
         tex_iterator_1++;
         if(tex_iterator_1 >= tex_size) tex_iterator_1 = 0;
    }
}



void init_models()
{
    init_character_model();

}

void init_character_model()
{
    load_model("data/models/body.obj", &character_model.body);
    load_model("data/models/shirt.obj", &character_model.shirt);
    load_model("data/models/shoes.obj", &character_model.shoes);
    load_model("data/models/socks.obj", &character_model.socks);
    load_model("data/models/shorts.obj", &character_model.shorts);
}

void draw_character(struct Character* character)
{
    set_material_character();
    float color[] = {0.5,0.25,0.0,1};
    if (character->blink_down_counter%7 > 3)
    {
        color[0] = 1.0;
        color[1] = 1.0;
        color[2] = 1.0;        
        color[3] = 1.0;
    }
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color);
    glBindTexture(GL_TEXTURE_2D, character_texture.skin);
    draw_model(&character_model.body);
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, &character->player_color.r);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, &character->player_color.r);
    glBindTexture(GL_TEXTURE_2D, character_texture.white_cloth);
    draw_model(&character_model.shirt);

    float color2[] = {1,1,1,1};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color2);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color2);    
    glBindTexture(GL_TEXTURE_2D, character_texture.white_cloth);
    draw_model(&character_model.shorts);    
    
    glBindTexture(GL_TEXTURE_2D, character_texture.white_cloth);
    draw_model(&character_model.socks);
    
    glBindTexture(GL_TEXTURE_2D, character_texture.plain_black);
    draw_model(&character_model.shoes);
    
}

void draw_sky()
{
    double theta, phi1, phi2;
    double x1, y1, z1;
    double x2, y2, z2;
    double u, v1, v2;

    int n_slices, n_stacks;
    double radius;
    int i, k;

    n_slices = 12;
    n_stacks = 6;

    glPushMatrix();
    int size = 300;
    glScaled(size,size,size);
    //glRotatef(45, 1, 0, 0);
	set_material_sky();
    
    glBindTexture(GL_TEXTURE_2D, ball_texture.cloudy_sky);
    
	glBegin(GL_TRIANGLE_STRIP);
    for (i = -1*n_stacks; i < n_stacks; ++i) {
        v1 = (double)i / n_stacks;
        v2 = (double)(i + 1) / n_stacks;
        phi1 = v1 * M_PI / 2.0;
        phi2 = v2 * M_PI / 2.0;
        for (k = 0; k <= n_slices; ++k) {
            u = (double)k / n_slices;
            theta = u * 2.0 * M_PI;
            x1 = cos(theta) * cos(phi1);
            y1 = sin(theta) * cos(phi1);
            z1 = sin(phi1);
            x2 = cos(theta) * cos(phi2);
            y2 = sin(theta) * cos(phi2);
            z2 = sin(phi2);
            glTexCoord2d(u, 1.0 - v1);
            glNormal3f(x1, y1, z1);
            glVertex3d(x1, y1, z1);
            glTexCoord2d(u, 1.0 - v2);
            glNormal3f(x2, y2, z2);
            glVertex3d(x2, y2, z2);
        }
    }

    glEnd();

    glPopMatrix(); 
    
    
}

void draw_triangles(const struct Model* model)
{
    int i, k;
    int vertex_index, texture_index, normal_index;
    double x, y, z, normal_x, normal_y, normal_z, u, v;

	glBegin(GL_TRIANGLES);

    for (i = 0; i < model->n_triangles; ++i) {
        for (k = 0; k < 3; ++k) {

            texture_index = model->triangles[i].points[k].texture_index;
            u = model->texture_vertices[texture_index].u;
            v = model->texture_vertices[texture_index].v;
            // NOTE: The 1-v is model file specific!
            glTexCoord2f(u, v);

            normal_index = model->triangles[i].points[k].normal_index;
            normal_x = model->normals[normal_index].x;
            normal_y = model->normals[normal_index].y;
            normal_z = model->normals[normal_index].z;
            glNormal3d(normal_x, normal_y, normal_z);

            vertex_index = model->triangles[i].points[k].vertex_index;
            x = model->vertices[vertex_index].x;
            y = model->vertices[vertex_index].y;
            z = model->vertices[vertex_index].z;
            glVertex3d(x, y, z);
        }
    }    

    glEnd();
}

void draw_quads(const struct Model* model)
{
    int i, k;
    int vertex_index, texture_index, normal_index;
    double x, y, z, u, v;

	glBegin(GL_QUADS);

    for (i = 0; i < model->n_quads; ++i) {
        for (k = 0; k < 4; ++k) {

            texture_index = model->quads[i].points[k].texture_index;
            u = model->texture_vertices[texture_index].u;
            v = model->texture_vertices[texture_index].v;
            // NOTE: The 1-v is model file specific!
            glTexCoord2f(u, -1 - v);

            vertex_index = model->quads[i].points[k].vertex_index;
            x = model->vertices[vertex_index].x;
            y = model->vertices[vertex_index].y;
            z = model->vertices[vertex_index].z;
            glVertex3d(x, y, z);
        }
    }    

    glEnd();
}

void draw_model(const struct Model* model)
{
    draw_triangles(model);
    draw_quads(model);
}


void draw_help()
{
    glBindTexture(GL_TEXTURE_2D, help_texture);
    int size = 1;
    glScaled(size,size,size);
    float amb[] = {1, 1, 1};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb);
    glBegin(GL_QUADS);
    glTexCoord2f(0,0);
    glVertex3f( -16, -9, 2);
    glTexCoord2f(1,0);
    glVertex3f( 16, -9, 2);
    glTexCoord2f(1,1);
    glVertex3f( 16, 9, 2);
    glTexCoord2f(0,1);
    glVertex3f( -16, 9, 2);
    glEnd();

}
