#include "Entity.h"

Entity::Entity(void):Node(){
	this->children = new std::vector<Entity*>();
	this->vertices = new std::vector<Vertex>();
	this->parent = nullptr;
	this->transform = new Transform();
}

Entity::~Entity(void){
}

void Entity::draw(glm::mat4 projectionMatrix, glm::mat4 viewMatrix){	
	
	vox::pushMatrix( transform->getModelMatrix());

	for(int i = 0; i<children->size(); i++){
		children->at(i)->draw(projectionMatrix, viewMatrix);
	}
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer->getVertexBufferId());
	glUseProgram(shader->getProgramId());	
	glm::mat4 mvp = projectionMatrix * viewMatrix * vox::modelMatrix();  	
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*vertices->size(), vertices->data(), GL_STATIC_DRAW);	
	GLuint mvpUniformLocation = glGetUniformLocation(shader->getProgramId(), "MVP");
	glUniformMatrix4fv(mvpUniformLocation, 1, GL_FALSE, &mvp[0][0]);
	vertexBuffer->renderVertexBuffer();
	
	vox::popMatrix();
}

void Entity::update(){
}

void Entity::addChild(Entity* child)
{
	child->setParent(this);
	children->push_back(child);

	child->transform->setParent(this->transform);
	transform->children->push_back(child->transform);
}

void Entity::removeChildAtIndex(int index){
	children->erase(children->begin()+index-1);
	transform->children->erase(transform->children->begin()+index-1);
}

void Entity::setParent(Entity* parent){
	this->parent = parent;
	transform->setParent(parent->transform);
}

void Entity::pushVert(Vertex vertex){
	vertices->push_back(vertex);
}
void Entity::setNormal(unsigned long int _vertId, float _x, float _y, float _z){
	vertices->at(_vertId).nx = _x;
	vertices->at(_vertId).ny = _y;
	vertices->at(_vertId).nz = _z;
}