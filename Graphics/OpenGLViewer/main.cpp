#include "window.h"
#include <QApplication>
#include "scene.h"
#include <iostream>

QString OpenGL_Model("re3dmodel/velociraptor_mesh_materials.dae");

// OpenGL ES 2.0, a single vertex buffer can have at max std::numeric_limits<unsigned short>::max() vertices,
// so use a smaller model if rendering with OpenGL ES
QString OpenGLES_Model("demon_head/demon_head.3ds");


int main(int argc, char *argv[])
{
    Model dino(OpenGL_Model, ModelLoader::RelativePath);

    Model dino2(OpenGL_Model, ModelLoader::RelativePath);

    Scene scene(&dino, &dino2);
    QApplication a(argc, argv);


    OpenGLWindow w1(&scene, 40, 4, 1);
    w1.show();

    return a.exec();
}
