// MyGLWidget.cpp
#include "MyGLWidget.h"
#include <iostream>
#include <stdio.h>

#define printOpenGLError() printOglError(__FILE__, __LINE__)
#define CHECK() printOglError(__FILE__, __LINE__,__FUNCTION__)
#define DEBUG() std::cout << __FILE__ << " " << __LINE__ << " " << __FUNCTION__ << std::endl;

int MyGLWidget::printOglError(const char file[], int line, const char func[]) 
{
    GLenum glErr;
    int    retCode = 0;

    glErr = glGetError();
    const char * error = 0;
    switch (glErr)
    {
        case 0x0500:
            error = "GL_INVALID_ENUM";
            break;
        case 0x501:
            error = "GL_INVALID_VALUE";
            break;
        case 0x502: 
            error = "GL_INVALID_OPERATION";
            break;
        case 0x503:
            error = "GL_STACK_OVERFLOW";
            break;
        case 0x504:
            error = "GL_STACK_UNDERFLOW";
            break;
        case 0x505:
            error = "GL_OUT_OF_MEMORY";
            break;
        default:
            error = "unknown error!";
    }
    if (glErr != GL_NO_ERROR)
    {
        printf("glError in file %s @ line %d: %s function: %s\n",
                             file, line, error, func);
        retCode = 1;
    }
    return retCode;
}

MyGLWidget::~MyGLWidget() {
}

void MyGLWidget::paintGL ()   // Mètode que has de modificar
{
  // En cas de voler canviar els paràmetres del viewport, descomenteu la crida següent i
// useu els paràmetres que considereu (els que hi ha són els de per defecte)
//  glViewport (0, 0, ample, alt);
  
  // Esborrem el frame-buffer i el depth-buffer
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Pintem el terra
  glBindVertexArray (VAO_Terra);
  modelTransformTerra ();
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

  // Pintem el Patricio
  glBindVertexArray (VAO_Patr);
  modelTransformPatricio ();
  glDrawArrays(GL_TRIANGLES, 0, patr.faces().size()*3);

  // Pintem el cub
  glBindVertexArray(VAO_Cub);
  float rotacionCubo1 = 0 * (2.0f * M_PI / 3.0f);
  modelTransformCub (2.0, rotacionCubo1);
  glDrawArrays(GL_TRIANGLES, 0, 36);
  
  float rotacionCubo2 = 1 * (2.0f * M_PI / 3.0f);
  modelTransformCub (2.5, rotacionCubo2);
  glDrawArrays(GL_TRIANGLES, 0, 36);

  float rotacionCubo3 = 2 * (2.0f * M_PI / 3.0f);
  modelTransformCub (3.0, rotacionCubo3);
  glDrawArrays(GL_TRIANGLES, 0, 36);

  glBindVertexArray(0);
}

void MyGLWidget::modelTransformCub (float escala, float angle) 
{
  TG = glm::mat4(1.f);
  TG = glm::rotate(TG, angle, glm::vec3(0.0f, 1.0f, 0.0f));
  TG = glm::translate(TG, glm::vec3(5.0f, 0.0f, 0.0f));
  TG = glm::scale(TG, glm::vec3(escala));
  TG = glm::scale(TG, glm::vec3(2.0f)); // Cubo de medida 1
  glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);
  // En aquest mètode has de substituir aquest codi per construir la 
  // transformació geomètrica (TG) del cub usant els paràmetres adientment
}

void MyGLWidget::modelTransformPatricio ()    // Mètode que has de modificar
{
  ExamGLWidget::modelTransformPatricio ();
}

void MyGLWidget::viewTransform ()    // Mètode que has de modificar
{
  if (!camPlanta)
    ExamGLWidget::viewTransform();
  else
  {
    // Codi per a la viewMatrix de la Càmera-2
  }
}

void MyGLWidget::projectTransform ()
{
  if (!camPlanta)
    ExamGLWidget::projectTransform();
  else
  {
    // Codi per a la projectMatrix de la Càmera-2
  }
}

void MyGLWidget::keyPressEvent(QKeyEvent* event) {
  makeCurrent();
  switch (event->key()) {
  case Qt::Key_V: {
      // ...
    break;
	}
  case Qt::Key_1: {
      // ...
    break;
	}
  case Qt::Key_2: {
      // ...
    break;
	}
  case Qt::Key_3: {
      // ...
    break;
	}
  case Qt::Key_F: {
      // ...
    break;
	}
  case Qt::Key_C: {
      // ...
    break;
	}
  case Qt::Key_Right: {
      // ...
    break;
	}
  case Qt::Key_Left: {
      // ...
    break;
	}
  case Qt::Key_R: {
      // ...
    break;
	}
  default: ExamGLWidget::keyPressEvent(event); break;
  }
  update();
}

