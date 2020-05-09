/*
 * Cette classe organise les modèles à représenter, ainsi que l'éclairage et la position de l'observateur. C'est un SupportADesssin.
 * Elle contient les shaders. Le déplacement est implémenté "à la minecraft" avec les touches WASD et la souris.
 * Il est aussi fluide, dans le sens où quand on relâche une touche le deplacement ralentit jusqu'à s'arrêter doucement.
 *
 * Camera: L'orientation de la caméra est donnée par deux angles, le yaw et pitch. Ceux-ci servent à définir la matrice de vue,
 * avec la fonction intégrée lookAt de Qt. Le déplacement fluide est implémenté par une simulation physique de frottement
 * visqueux, avec un intégrateur Euler-Cromer qui borne aussi la vitesse maximale. Appuyer sur une touche ajoute donc un peux
 * d'accélération dans une direction.
 *
 * Aussi: l'axe y est vertical ici.
 */


#pragma once
#include <string>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLFunctions_4_3_Core>
#include <QOpenGLFunctions>
#include <vector>
#include "modelloader.h"
#include "Graphics/SupportADessin.h"
#include "model.h"
#include "Interface/System/Systeme.h"
#include <memory>
#include <QtCharts>

class Toupie;
class Integrateur;
class Scene : public SupportADessin, QOpenGLFunctions
{
    friend class GLWindow;
    friend class Simulator;
public:

    void initialize();
    void resize(int w, int h);
    void update();
    void integrateSystem(const double& dt, const int& integSubDiv);
    void cleanup();


    Systeme system;


private:
    //le constructeur est privé pour être uniquement accessible depuis GLWidget

    explicit Scene(Integrateur* integrateur): system(this, integrateur) {}
    //chargement des shaders
    static void createShaderProgram(QOpenGLShaderProgram& shaderProgram, const QString& vShader, const QString& fShader);

    //mise en place de l'éclairage et des matrices de vue et de projection.
    void setupLightingAndMatrices();

    //dessin des modèles de toupie
    void dessine(const Toupie&) const override;

    //dessin du système entier
    void dessine(const Systeme&) const override;
    //dessin des modèles de toupie
    void dessine(const double &, const Toupie& toupie) const override {dessine(toupie);}

    //dessin du système entier
    void dessine(const double &, const Systeme& systeme) const override {dessine(systeme);}


    //mutable car de cette manière la méthode dessine(cont Toupie&) peut être const.
    mutable QOpenGLShaderProgram m_shaderProgram; //pour les modèles
    mutable QOpenGLShaderProgram t_shaderProgram; //pour les tracés de points
    QMatrix4x4 m_projection, m_view;

    LightInfo m_lightInfo;

    QVector3D r, v, a;
    QVector3D direction;
    QVector3D directionXZPlane;
    //le déplacement du système
    void deplacer(const double& dt, bool up,bool down,bool forw,bool back,bool left,bool right);

    //Modification des angles
    void DeltaPitchYaw(const float& p, const float& y);

    Model table = Model(QString("Graphics/OpenGLViewer/Models/table.3DS"),ModelLoader::RelativePath);

    float pitch = 0, yaw = 0;

    float zoomFactor = 1;
    void setZoomPerspectiveMatrix(const int& width, const int& height);
    float scaleFactor = 1;
    void setScaleFactor(const float& scale) {scaleFactor = scale;}

    float traceBuffer[600] = {};
    std::vector<std::unique_ptr<QOpenGLVertexArrayObject> > QtGVAOs;
    std::vector<std::unique_ptr<QOpenGLBuffer> > QtGVBOs;
    std::vector<std::unique_ptr<QOpenGLVertexArrayObject> > QtAVAOs;
    std::vector<std::unique_ptr<QOpenGLBuffer> > QtAVBOs;


};


