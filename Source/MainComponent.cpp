/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#define PI 3.1415926535897932384
#define NOTES_PER_OCTAVE 12
#define FIFTH 7
//==============================================================================
MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
    // you add any child components.
    setSize (800, 800);
    
}



MainComponent::~MainComponent()
{
    // This shuts down the GL system and stops the rendering calls.
    shutdownOpenGL();
}

//==============================================================================
void MainComponent::initialise()
{
    // Initialise GL objects for rendering here.
    setRadius();
    numPoints = 12;
    slice = 2 * PI / numPoints;
    offset = circleRadius / 23.0f;
}

void MainComponent::shutdown()
{
    // Free any GL objects created for rendering here.
}
void MainComponent::setRadius(){
    if(getWidth() < getHeight())
        circleRadius = getWidth();
    else
        circleRadius = getHeight();
}
void MainComponent::render()
{
    OpenGLHelpers::clear (Colours::black);
    
    // Points in 3D space
    GLfloat verts[]
    {
        -1.0f,-1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f,  1.0f, 0.0f
    };
//    Array<GLfloat> triModel {
//        0.0f,  0.0f, 0.0f,
//        1.0f, -1.0f, 0.0f,
//        0.0f,  1.0f, 0.0f
//    };
    //verts.g
//    Array<GLfloat> verts;
//
//    for(int i = 0; i < 12; i++){
//        verts.add(0.0);
//        verts.add(0.0);
//        verts.add(0.0);
//
//        float angle = slice * ((i + 9) % 12);
//        int newX = (int) getWidth() / 2.0f + (circleRadius / 2.0f + offset) * cos(angle);
//        int newY = (int) getHeight()/ 2.0f + (circleRadius / 2.0f + offset) * sin(angle);
//
//    }
    // An ID for your buffer
    GLuint bufferID;
    
    // Get the ID
    openGLContext.extensions.glGenBuffers (1, &bufferID);
    
    // Configure the buffer
    openGLContext.extensions.glBindBuffer (GL_ARRAY_BUFFER, bufferID);
    
    // Let GL know about our veritices
    openGLContext.extensions.glBufferData (GL_ARRAY_BUFFER, sizeof (verts), verts, GL_STATIC_DRAW);
    
    openGLContext.extensions.glEnableVertexAttribArray (0);
    
    openGLContext.extensions.glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    
    // Draw three verticies
    glDrawArrays (GL_TRIANGLES, 0, 3);
    
    openGLContext.extensions.glDisableVertexAttribArray (0);
}
//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // You can add your component specific drawing code here!
    // This will draw over the top of the openGL background.
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
