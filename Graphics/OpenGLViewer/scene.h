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
 *
 * Cette classe est censée ne jamais être utilisée seule, elle fonctionne en conjonction avec GLWindow. C'est pourquoi son constructeur est privé
 * et elle est amie avec GLWindow.
 */


#pragma once
#include <string>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLFunctions_4_4_Core>
#include <QOpenGLFunctions>
#include <vector>
#include "modelloader.h"
#include "Graphics/SupportADessin.h"
#include "model.h"
#include "Interface/System/Systeme.h"
#include "GLTrace.h"
#include <memory>

class Toupie;
class Integrateur;
class Scene : public SupportADessin, public QOpenGLFunctions
{
    friend class GLWindow;
    friend class Simulator;
public:

    void initialize();
    void resize(int w, int h);
    void update();
    void integrateSystem(const double& dt, const int& integSubDiv);
    void setDevicePixelRatio(int pr) {devicePixelRatio = pr;}

    Systeme system;


private:
    //le constructeur est privé pour être uniquement accessible depuis GLWidget

    explicit Scene(Integrateur* integrateur, const int& screenw, const int& screenh, const int& traceLength, const QString& tableModelpath = "");
    //chargement des shaders
    static void createShaderProgram(QOpenGLShaderProgram& shaderProgram, const QString& vShader, const QString& fShader);

    //mise en place de l'éclairage et des matrices de vue et de projection.
    void setupLightingAndMatrices();

    //dessin des modèles de toupie
    void dessine(const Toupie&) const override;
    void dessine(const Toupie & toupie, QOpenGLShaderProgram&) const;

    //dessin du système entier
    void dessine(const Systeme&) const override;
    void dessineSystem(QOpenGLShaderProgram &shaderProgram) const;

    //dessin des modèles de toupie
    void dessine(const double &, const Toupie& toupie) const override {dessine(toupie);}

    //dessin du système entier
    void dessine(const double &, const Systeme& systeme) const override {dessine(systeme);}


    std::vector<const Toupie *> toupies; //les toupies
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

    Model* table; //le modèle de table

    float pitch = 0, yaw = 0; //l'orientation dans l'espace, modifiable par la souris (via GLWindow, le parent)

    float zoomFactor = 1; //facteur de zoom
    void setZoomPerspectiveMatrix(const int& width, const int& height); //nécessaire pour implémenter le zoom
    float scaleFactor = 1; //facteur de "scale" des modèles, on agrandit les grandeurs dans les trois dimensions de l'espace
    void setScaleFactor(const float& scale) {scaleFactor = scale;} //logique


    const unsigned int SHADOW_WIDTH = 2048, SHADOW_HEIGHT = 2048;
    unsigned int depthMapFBO;
    unsigned int depthMap;

    float borderColor[4] = { 1.0, 1.0, 1.0, 1.0 };

    QVector3D lightPos;
    QMatrix4x4 lightProjection, lightView;
    QMatrix4x4 lightSpaceMatrix;
    float near_plane = 1.0f, far_plane = 15.5f;

    int SCR_WIDTH, SCR_HEIGHT;
    int devicePixelRatio = 1;

    size_t traceLength;
    std::vector<std::unique_ptr<GLTrace> > GTraces;
    std::vector<std::unique_ptr<GLTrace> > ATraces;

    void addToTraces();

    size_t runCount = 0;
};


