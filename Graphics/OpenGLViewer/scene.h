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


    Systeme system;


private:
    //le constructeur est privé pour être uniquement accessible depuis GLWidget

    explicit Scene(Integrateur* integrateur, int screenw, int screenh): system(this, integrateur), SCR_WIDTH(screenw), SCR_HEIGHT(screenh) {}
    //chargement des shaders
    static void createShaderProgram(QOpenGLShaderProgram& shaderProgram, const QString& vShader, const QString& fShader);

    //mise en place de l'éclairage et des matrices de vue et de projection.
    void setupLightingAndMatrices();

    //dessin des modèles de toupie
    void dessine(const Toupie&) const override;
    void dessine(const Toupie & toupie, QOpenGLShaderProgram&) const;

    //dessin du système entier
    void dessine(const Systeme&) const override;
    void dessine(const Systeme&, QOpenGLShaderProgram&) const;

    //dessin des modèles de toupie
    void dessine(const double &, const Toupie& toupie) const override {dessine(toupie);}

    //dessin du système entier
    void dessine(const double &, const Systeme& systeme) const override {dessine(systeme);}


    //mutable car de cette manière la méthode dessine(cont Toupie&) peut être const.
    mutable QOpenGLShaderProgram m_shaderProgram; //pour les modèles
    mutable QOpenGLShaderProgram t_shaderProgram; //pour les tracés de points
    mutable QOpenGLShaderProgram shadow_shaderProgram; //pour les tracés de points
    QMatrix4x4 m_projection, m_view;

    LightInfo m_lightInfo;

    QVector3D r, v, a;
    QVector3D direction;
    QVector3D directionXZPlane;
    //le déplacement du système
    void deplacer(const double& dt, bool up,bool down,bool forw,bool back,bool left,bool right);

    //Modification des angles
    void DeltaPitchYaw(const float& p, const float& y);

    Model table = Model(QString("Graphics/OpenGLViewer/Models/table.3DS"),ModelLoader::RelativePath); //le modèle de table

    float pitch = 0, yaw = 0; //l'orientation dans l'espace, modifiable par la souris (via GLWindow, le parent)

    float zoomFactor = 1; //facteur de zoom
    void setZoomPerspectiveMatrix(const int& width, const int& height); //nécessaire pour implémenter le zoom
    float scaleFactor = 1; //facteur de "scale" des modèles, on agrandit les grandeurs dans les trois dimensions de l'espace
    void setScaleFactor(const float& scale) {scaleFactor = scale;} //logique



    float traceBuffer[600] = {}; //nécessaire comme intermédiaire entre les deques utilisées pour les traces et le buffer
    std::vector<std::unique_ptr<QOpenGLVertexArrayObject> > QtGVAOs; //Ces 4 objets sont des objets opengl qui contiennent l'information pour dessiner les points des traces
    std::vector<std::unique_ptr<QOpenGLBuffer> > QtGVBOs;
    std::vector<std::unique_ptr<QOpenGLVertexArrayObject> > QtAVAOs;
    std::vector<std::unique_ptr<QOpenGLBuffer> > QtAVBOs;


    const unsigned int SHADOW_WIDTH = 2048, SHADOW_HEIGHT = 2048;
    unsigned int depthMapFBO;
    unsigned int depthMap;

    float borderColor[4] = { 1.0, 1.0, 1.0, 1.0 };

    QVector3D lightPos;
    QMatrix4x4 lightProjection, lightView;
    QMatrix4x4 lightSpaceMatrix;
    float near_plane = 1.0f, far_plane = 15.5f;

    int SCR_WIDTH, SCR_HEIGHT;
};


