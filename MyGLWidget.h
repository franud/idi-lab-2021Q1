#include "ExamGLWidget.h"

class MyGLWidget:public ExamGLWidget
{
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : ExamGLWidget(parent) {}
    ~MyGLWidget();

  protected:
    virtual void paintGL ();
    virtual void keyPressEvent(QKeyEvent* event);
    virtual void modelTransformCub (float escala, float angle);
    virtual void modelTransformPatricio ();
    virtual void projectTransform ();
    virtual void viewTransform ();

  private:
    int printOglError(const char file[], int line, const char func[]);
    bool cubosVisibles = true;
    struct DatosCubos{
      float rotacion;
      float size;
    };

    struct DatosPatricio{
      int estado;
      float size;
    };

    DatosCubos cubo1 = {.rotacion = 0 * (2.0f * M_PI / 3.0f), .size = 2.0f};
    DatosCubos cubo2 = {.rotacion = 1 * (2.0f * M_PI / 3.0f), .size = 2.5f};
    DatosCubos cubo3 = {.rotacion = 2 * (2.0f * M_PI / 3.0f), .size = 3.0f};

    DatosPatricio patricio = {.estado = 0, .size = 2};

};
