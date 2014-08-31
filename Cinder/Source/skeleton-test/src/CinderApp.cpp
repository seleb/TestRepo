#include "cinder/MayaCamUI.h"
#include "cinder/TriMesh.h"
#include "cinder/app/AppBasic.h"
#include "cinder/gl/Fbo.h"
#include "cinder/gl/GlslProg.h"
#include "cinder/gl/Light.h"
#include "cinder/gl/Material.h"
#include "cinder/params/Params.h"

#include "string.h"
#include <sstream>

#include "SkeletonData.h"


using namespace ci;
using namespace ci::app;
using namespace std;

class CinderApp : public AppBasic {
public:
	void prepareSettings(Settings *settings);

	void setup();
	void update();
	void draw();

	void saveSkeleton();

	//! loads the shaders
	void loadShaders();
	
protected:
	vector<Joint *> m_joints;

	SkeletonData * s;

	//! our Phong shader, which supports multiple targets
	gl::GlslProg	mPhongShader;

	params::InterfaceGlRef params;
	string directory;
	string fileName;
};

void CinderApp::prepareSettings(Settings *settings){
	settings->setWindowSize(900, 600);
	settings->setFrameRate(100.0f);
	settings->setTitle("Saving Bone Data");
}

void CinderApp::setup(){

	m_joints = vector<Joint *>();
	
	Joint * b1 = new Joint();
	b1->pos = Vec3f(-1.0666666666666667,0.00000000000000000,0.31333333333333324);
	Joint * b2 = new Joint();
	b2->pos = Vec3f(-1.0733333333333333,0.00000000000000000,-0.83999999999999997);
	b2->parent = b1;
	Joint * b3 = new Joint();
	b3->pos = Vec3f(0.99333333333333318,0.00000000000000000,-0.82000000000000006);
	b3->parent = b2;
	Joint * b4 = new Joint();
	b4->pos = Vec3f(0.99333333333333318,0.00000000000000000,0.82666666666666666);
	b4->parent = b3;
	Joint * b5 = new Joint();
	b5->pos = Vec3f(-1.0800000000000001,0.00000000000000000,0.46666666666666656);
	b5->parent = b4;

	m_joints.push_back(b1);
	m_joints.push_back(b2);
	m_joints.push_back(b3);
	m_joints.push_back(b4);
	m_joints.push_back(b5);

	console() << "setup" << endl;
	s = new SkeletonData();
	/*s->setDirectory("C:/");
	s->setFileName("BONES.txt");
	console() << "saveSkeleton" << endl;
	s->SaveSkeleton(m_joints);*/
	
	params = params::InterfaceGl::create("Save File", Vec2i(300,150));
	params->addParam("Directory", &directory);
	params->addParam("File Name", &fileName);
	params->addButton("Save", std::bind( &CinderApp::saveSkeleton, this ), "min=100");
}

void CinderApp::saveSkeleton() {
	s->setDirectory(directory);
	s->setFileName(fileName);
	console() << "saveSkeleton" << endl;
	s->SaveSkeleton(m_joints);
}

void CinderApp::update(){}

void CinderApp::draw(){
	params->draw();
	
}

void CinderApp::loadShaders()
{
	try{
		mPhongShader = gl::GlslProg( loadFile("../assets/shaders/phong.vert"), loadFile("../assets/shaders/phong.frag") );
	}catch( const std::exception &e ) {
		console() << e.what() << std::endl;
		quit();
	}
}


CINDER_APP_BASIC( CinderApp, RendererGl )