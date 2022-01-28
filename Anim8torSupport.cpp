#include "Anim8torSupport.h"

void Anim8torSupport::draw(struct Anim8orObject* obj) {

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);

	for (int m = 0; m < obj->nMeshes; m++) {
		glColor4fv(obj->meshes[m]->materials[0].diffuse);
		glVertexPointer(3, GL_FLOAT, 0, obj->meshes[m]->coordinates);
		glNormalPointer(GL_FLOAT, 0, obj->meshes[m]->normals);
		glDrawElements(GL_TRIANGLES, obj->meshes[m]->nIndices, GL_UNSIGNED_INT, obj->meshes[m]->indices);
	}

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
}

void Anim8torSupport::drawTex(Anim8orObject* obj, int tex_id)
{
	if(tex_id != -1)
		glBindTexture(GL_TEXTURE_2D, tex_id);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	for (int m = 0; m < obj->nMeshes; m++) {
		glColor4fv(obj->meshes[m]->materials[0].diffuse);
		glVertexPointer(3, GL_FLOAT, 0, obj->meshes[m]->coordinates);
		glNormalPointer(GL_FLOAT, 0, obj->meshes[m]->normals);
		glTexCoordPointer(2, GL_FLOAT, 0, obj->meshes[m]->texcoords);
		glDrawElements(GL_TRIANGLES, obj->meshes[m]->nIndices, GL_UNSIGNED_INT, obj->meshes[m]->indices);
	}

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}
