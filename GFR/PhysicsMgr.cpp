#include "PhysicsMgr.h"

using namespace framework;

PhysicsMgr::~PhysicsMgr()
{
	delete m_World;
}

b2Body* PhysicsMgr::CreateStaticBody(f32 originX, f32 originY, f32 angleRadians, 
								  f32 linearDamping, f32 angularDamping, f32 gravityScale, 
								  bool allowSleep, bool isAwake, bool isRotationFixed, 
								  void* userData)
{
	b2BodyDef def;
	def.type			= b2_staticBody;
	def.position.Set(originX, originY);
	def.angle			= angleRadians;
	def.linearDamping	= linearDamping;
	def.angularDamping	= angularDamping;
	def.gravityScale	= gravityScale;
	def.allowSleep		= allowSleep;
	def.awake			= isAwake;
	def.fixedRotation	= isRotationFixed;
	def.userData		= userData;

	return m_World->CreateBody(&def);
};

b2Body* PhysicsMgr::CreateDynamicBody(f32 originX, f32 originY, f32 angleRadians, 
								  f32 linearDamping, f32 angularDamping, f32 gravityScale, 
								  bool allowSleep, bool isAwake, bool isRotationFixed, bool isBullet, 
								  void* userData)
{
	b2Body* body = CreateStaticBody(originX, originY, angleRadians, linearDamping, angularDamping,
		gravityScale, allowSleep, isAwake, isRotationFixed, userData);
	body->SetType(b2_dynamicBody);
	body->SetBullet(isBullet);

	return body;
};

void PhysicsMgr::DestroyBody(b2Body* body)
{
	m_World->DestroyBody(body);
};

void PhysicsMgr::Update(f32 deltaTime, u32 velocityIterations, u32 positionIterations)
{
	// World must be created before physics can be updated.
	assert(m_World == NULL);

	m_World->Step(deltaTime, velocityIterations, positionIterations);
	m_World->ClearForces();
};

void PhysicsMgr::CreateWorld(f32 gravityX, f32 gravityY, bool allowSleep)
{
	b2Vec2 gravityVec = b2Vec2(gravityX, gravityY);
	m_World = new b2World(gravityVec);
	m_World->SetAllowSleeping(allowSleep);
};