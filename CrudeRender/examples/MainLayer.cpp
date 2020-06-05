//
//  MainLayer.cpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/11/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#include "MainLayer.hpp"

using namespace Crude;
using namespace Crude::Utils;

MainLayer::MainLayer()
: Layer("Main0"), m_OCamController(16.f/9.f), m_PCamController(16.f/9.f, glm::radians(45.f))
{
    
}

void MainLayer::onAttach()
{
    
   
    
    
    //m_FlatColourShader = new Shader("CrudeAssets/shadersources/colourShader.vs", "CrudeAssets/shadersources/colourShader.fs");
    //m_TextureShader = new Shader("CrudeAssets/shadersources/textureShader.vs", "CrudeAssets/shadersources/textureShader.fs");
    
    m_FlatColourShader.loadFromFile("examples/CrudeAssets/shadersources/colourShader.vs", "examples/CrudeAssets/shadersources/colourShader.fs");
    m_TextureShader.loadFromFile("examples/CrudeAssets/shadersources/textureShader.vs", "examples/CrudeAssets/shadersources/textureShader.fs");
    
    
    //m_Shader = std::make_unique<Shader>("/Users/Herve/Documents/CrudeRender/CrudeRender/assets/shadersources/mainShader.vs", "/Users/Herve/Documents/CrudeRender/CrudeRender/assets/shadersources/mainShader.fs");
    //static Shader basicShad("CrudeAssets/shadersources/mainShader.vs", "CrudeAssets/shadersources/mainShader.fs");
    //Renderer::addShader(m_Shader, "Basic");
    
    
    
    float vertices[]
    {
        
         0.5f,  0.5f, 0.0f,   1.0f, 1.0f,
        -0.5f,  0.5f, 0.0f,   0.0f, 1.0f,
         0.5f, -0.5f, 0.0f,   1.0f, 0.0f,
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f,
    };
    unsigned int indices[]
    {
        0, 1, 3,
        0, 2, 3,
    };
    
    /*unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);*/
    
    m_vao.bind();
    
    static VertexBuffer vbo(vertices, sizeof(vertices));
    VertexBufferLayout layout;
    layout.pushFloat(3);
    layout.pushFloat(2);
    
    static IndexBuffer ibo(indices, 6);
    
    //Crude::VertexArray vao;
    m_vao.addVertexBuffer(vbo, layout);
    m_vao.addIndexBuffer(ibo);
    
    //m_vao.unbind();*/
    
    int width = Application::get().getWindow().getWidth();
    int height = Application::get().getWindow().getHeight();
    float aspectRatio = (float)width/(float)height;
    
    
    //m_OrthoCam = new OrthoCamera(-aspectRatio, aspectRatio, -1.f, 1.f);
    //m_OrthoCam->setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
    
    glm::vec4 test = {0.f, 0.f, 0.f, 0.f};
    test = m_PCamController.getCamera().getViewProjectionMatrix() * test;
    //LOG_TRACE("Test Coord: {0}, {1}, {2}", test.x, test.y, test.z);
    
    //m_OCamController.getCamera().setProjection(-aspectRatio, aspectRatio, -1.f, 1.f);
    //m_PerspecCam.setPosition(glm::vec3(0.0f, 0.0f, -3.0f));
    //m_PerspecCam = new PerspecCamera(glm::radians(45.f), aspectRatio, 0.1f, 100.f);
    //m_PerspecCam->setPosition(glm::vec3(0.0f, 0.0f, -3.0f));
    
    m_PCamController.getCamera().setPosition(glm::vec3(0.0f, 0.0f, 6.0f));
    m_PCamController.setBaseFOV(glm::radians(45.f));
    m_PCamController.setFOVBounds(glm::radians(10.f), glm::radians(140.f));
    
    
    /*m_ContainerTexture = new Texture("CrudeAssets/textures/container.png");
    m_FaceTexture = new Texture("CrudeAssets/textures/awesomeface.png");
    m_BlendTexture = new Texture("CrudeAssets/textures/circleSprite.png");
    
    m_TextureLibrary.add("container", *m_ContainerTexture);
    m_TextureLibrary.add("awesomeface", *m_FaceTexture);
    m_TextureLibrary.add("circle", *m_BlendTexture);*/
    m_TextureLibrary.load("container", "examples/CrudeAssets/textures/container.png");
    m_TextureLibrary.load("awesomeface", "examples/CrudeAssets/textures/awesomeface.png");
    m_TextureLibrary.load("circle", "examples/CrudeAssets/textures/circleSprite.png");
    m_TextureLibrary.load("square", "examples/CrudeAssets/textures/squareSprite.png");
    
    
    m_TextureShader.setInt("u_Texture1", 0);
    
    //RenderCommands::enableVSync(true);
    RenderCommands::setClearColour(1.0f, 0.4f, 0.2f, 1.0f);
    //RenderCommands::enableDepthTesting(true);
    RenderCommands::enableBlending(true);
    
    //RenderCommands::enableWireframeMode(true);
    
}

void MainLayer::onUpdate(Timestep deltaTime)
{
    //LOG_TRACE(deltaTime);
    m_OCamController.onUpdate(deltaTime);
    //m_PCamController.onUpdate(deltaTime);

    //glClearColor(1.0f, 0.4f, 0.2f, 1.0f);
    //glClear(GL_COLOR_BUFFER_BIT);
    
    //glm::vec4 testCoord(1.0f);
    //testCoord = viewProjection * model * testCoord;
    //LOG_TRACE("Test Coord: {0}, {1}, {2}", testCoord.x, testCoord.y, testCoord.z);
    //std::cout<< testCoord.x << ", " << testCoord.y << ", " << testCoord.z <<std::endl;
    
    //glm::mat4 viewProjection = m_OrthoCam->getViewProjectionMatrix();
    //glm::mat4 viewProjection = m_PerspecCam->getViewProjectionMatrix();
    //glm::mat4 viewProjection = m_OCamController.getCamera().getViewProjectionMatrix();
    
    
    //m_Shader->bind();
    //m_Shader->setMat4("u_ViewProjection",  viewProjection);
    RenderCommands::clearColourBuffer();
    RenderCommands::clearDepthBuffer();
    
    Renderer::beginScene(m_OCamController.getCamera());
    //Renderer::useShader("Basic");
   
    glm::mat4 model(1.0f);
    //model = glm::rotate(model, glm::radians(70.f), glm::vec3(1.0f, 0.f, 0.f));
    //model = glm::translate(model, m_Pos);
    
    glm::mat4 model2(1.0f);
    static float angle;
    angle += deltaTime;
    model = glm::translate(model, glm::vec3(3.f, 2.f, 0.f));
    
    model2 = glm::translate(model2, m_Pos);
    model2 = glm::rotate(model2, angle, glm::vec3(0.f, 0.f, 1.f));
    
   
    Renderer::useShader(m_FlatColourShader);
    m_FlatColourShader.setVec4f("u_Colour", 0.5f, 0.5f, 1.0f, 1.0f);
    Renderer::submit(m_vao, model);
    //m_FlatColourShader->setVec4f("u_Colour", 0.1f, 0.5f, 0.3f, 1.0f);
    //Renderer::submit(m_vao, model2);
    Renderer::useShader(m_TextureShader);
    m_TextureLibrary.get("circle")->bind();
    //m_BlendTexture->bind(0);
    Renderer::submit(m_vao, model2);
    m_TextureLibrary.get("square")->bind();
    //m_FaceTexture->bind(0);
    Renderer::submit(m_vao, glm::translate(glm::mat4(1.0f), glm::vec3(-2.f, -2.f, 0.0f)));
    
    
    //Renderer::draw(m_vao, glm::vec4(0.5f, 0.5f, 1.0f, 1.0f), model);
    //Renderer::draw(m_vao, glm::vec4(0.1f, 0.5f, 0.3f, 1.0f), model2);
    
    
   // m_Shader->setMat4("u_Model", model);
    //m_Shader->setVec4f("u_Colour", 0.5f, 0.5f, 1.0f, 1.0f);

    //m_vao.bind();
    //glDrawElements(GL_TRIANGLES, m_vao.getIndexBuffer().getCount(), GL_UNSIGNED_INT, nullptr);
    
    Renderer::endScene();

}

void MainLayer::onImGuiRender()
{
    ImGui::ShowCrudeDockSpace();
    ImGui::ShowDemoWindow();
    float f3[] {m_OCamController.m_CameraPosition.x, m_OCamController.m_CameraPosition.y, 0.0f};
    
    
    ImGui::Begin("Vars");
    ImGui::SliderFloat("X", &m_Pos.x, -10.0f, 10.0f);
    ImGui::SliderFloat("Y", &m_Pos.y, -10.0f, 10.0f);
    ImGui::SliderFloat("Z", &m_Pos.z, -10.0f, 10.0f);
    ImGui::InputFloat3("Camera Pos", f3);
    
    
    ImGui::End();

    m_OCamController.m_CameraPosition.x = f3[0];
    m_OCamController.m_CameraPosition.y = f3[1];
    m_OCamController.m_CameraPosition.z = f3[2];
    
}

void MainLayer::onEvent(Crude::Event& event)
{
    m_OCamController.onEvent(event);
    m_PCamController.onEvent(event);
    
    Crude::EventDispatcher dispatcher(event);
    dispatcher.dispatch<WindowResizeEvent>(BIND_EVENT_FN(MainLayer::onWindowResizeEvent));
    dispatcher.dispatch<Crude::KeyTypedEvent>(BIND_EVENT_FN(MainLayer::onKeyTypedEvent));
}

bool MainLayer::onWindowResizeEvent(WindowResizeEvent& event)
{
    //LOG_TRACE(event);
    int width = event.getWidth();
    int height = event.getHeight();
    float aspectRatio = (float)width/(float)height;
    //LOG_TRACE(aspectRatio);
    //m_PerspecCam->setAspectRatio(aspectRatio);
    //m_OrthoCam->setProjection(-aspectRatio, aspectRatio, -1.f, 1.f);
    return true;
}

bool MainLayer::onKeyTypedEvent(Crude::KeyTypedEvent& event)
{
    LOG_TRACE("Key not captured");
    return true;
}


void MainLayer::onDetach()
{
    LOG_TRACE("DETATCHED");
}
