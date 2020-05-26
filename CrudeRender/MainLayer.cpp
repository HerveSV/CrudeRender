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
    
    /*const char* vert =
    "#version 410 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "gl_Position = vec4(aPos, 1.0f);\n"
    "}\n";
    
    const char* frag =
    "#version 410 core\n"
    "out vec4 FragColour;\n"
    "void main()\n"
    "{\n"
    "FragColour = vec4(1.0f, 0.3f, 0.5f, 1.0f);\n"
    "}\n";*/
    
    /*unsigned int vertexShader = 0;
     vertexShader = glCreateShader(GL_VERTEX_SHADER);
     glShaderSource(vertexShader, 1, &vert, NULL);
     glCompileShader(vertexShader);
     
     //checking for compile time errors, in this case for the vertex shader compilation
     int  success;
     char infoLog[512];
     glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success); //checks if comp. is successful and stores it in the int
     if(!success)
     {
     glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
     std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
     }
     
     unsigned int fragmentShader = 0;
     fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
     glShaderSource(fragmentShader, 1, &frag, NULL);
     glCompileShader(fragmentShader);
     
     glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success); //checks if comp. is successful and stores it in the int
     if(!success)
     {
     glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
     std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
     }
     
     unsigned int shaderProgram1 = 0;
     shaderProgram1 = glCreateProgram();
     glAttachShader(shaderProgram1, vertexShader);
     glAttachShader(shaderProgram1, fragmentShader);
     glLinkProgram(shaderProgram1);
     
     glUseProgram(shaderProgram1);*/
    
    
    /*Crude::VertexArray vao;
     vao.bind();
     Crude::VertexBuffer vbo(vertices, sizeof(vertices));
     Crude::VertexBufferLayout layout;
     layout.push<float>(3);
     Crude::IndexBuffer ebo(indices, 6);
     
     vao.addVertexBuffer(vbo, layout);
     vao.addIndexBuffer(ebo);*/
    
    
    //
    /*unsigned int vao, ebo;
     
     glGenVertexArrays(1, &vao);
     glBindVertexArray(vao);
     
     //glBindBuffer(GL_ARRAY_BUFFER, vbo.getID());
     //vbo.bind();
     unsigned int vbo;
     glGenBuffers(1, &vbo);
     glBindBuffer(GL_ARRAY_BUFFER, vbo);
     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
     //Crude::VertexBuffer* vbo = new Crude::VertexBuffer(&vertices, sizeof(vertices));
     glEnableVertexAttribArray(0);
     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
     
     glGenBuffers(1, &ebo);
     glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
     glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);*/
    
    //m_shader = Crude::Shader(vert, frag);
    //m_shader.bind();
    
    /*unsigned int vbo, ebo;
     glGenBuffers(1, &vbo);
     glBindBuffer(GL_ARRAY_BUFFER, vbo);
     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
     glEnableVertexAttribArray(0);
     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
     
     glGenBuffers(1, &ebo);
     glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
     glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);/**/
    //glBindVertexArray(vao);
    
    
    m_Shader = new Shader("CrudeAssets/shadersources/mainShader.vs", "CrudeAssets/shadersources/mainShader.fs");
    //m_Shader = std::make_unique<Shader>("/Users/Herve/Documents/CrudeRender/CrudeRender/assets/shadersources/mainShader.vs", "/Users/Herve/Documents/CrudeRender/CrudeRender/assets/shadersources/mainShader.fs");
    //static Shader basicShad("CrudeAssets/shadersources/mainShader.vs", "CrudeAssets/shadersources/mainShader.fs");
    Renderer::addShader(m_Shader, "Basic");
    
    
    
    float vertices[]
    {
        
        0.5f, 0.5f, 0.0f,
        -0.5f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
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
    
    static IndexBuffer ibo(indices, 6);
    
    //Crude::VertexArray vao;
    m_vao.addVertexBuffer(vbo, layout);
    m_vao.addIndexBuffer(ibo);
    
    //m_vao.unbind();*/
    
    int width = Application::get().getWindow().getWidth();
    int height = Application::get().getWindow().getHeight();
    float aspectRatio = (float)width/(float)height;
    
    
    m_OrthoCam = new OrthoCamera(-aspectRatio, aspectRatio, -1.f, 1.f);
    m_OrthoCam->setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
    
    glm::vec4 test = {0.f, 0.f, 0.f, 0.f};
    test = m_PCamController.getCamera().getViewProjectionMatrix() * test;
    //LOG_TRACE("Test Coord: {0}, {1}, {2}", test.x, test.y, test.z);
    
    //m_OCamController.getCamera().setProjection(-aspectRatio, aspectRatio, -1.f, 1.f);
    //m_PerspecCam.setPosition(glm::vec3(0.0f, 0.0f, -3.0f));
    m_PerspecCam = new PerspecCamera(glm::radians(45.f), aspectRatio, 0.1f, 100.f);
    m_PerspecCam->setPosition(glm::vec3(0.0f, 0.0f, -3.0f));
    
    m_PCamController.getCamera().setPosition(glm::vec3(0.0f, 0.0f, 6.0f));
    m_PCamController.setBaseFOV(glm::radians(45.f));
    m_PCamController.setFOVBounds(glm::radians(10.f), glm::radians(140.f));
    //m_PCamController.setZoom(1.0f);
    
    //m_TestCam = new OrthographicCamera(-aspectRatio, aspectRatio, -1.f, 1.f);
    //m_TestCam->SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));
    //cam.setProjection(-720.f/2, 720.f/2, 1280.f/2, -1280.f/2, -1.f, 1.f);
    
    //LOG_INFO("Stuff: {0}", m_vao.getIndexBuffer().getCount());
    //m_Shader = Crude::Shader("assets/shadersources/mainShader.vs", "assets/shadersources/mainShader.fs");
    //m_Shader->bind();
}

void MainLayer::onUpdate(Timestep deltaTime)
{
    m_OCamController.onUpdate(deltaTime);
    m_PCamController.onUpdate(deltaTime);
    
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
    
    Renderer::beginScene(&m_OCamController.getCamera());
    Renderer::useShader("Basic");
    
    glm::mat4 model(1.0f);
    //model = glm::rotate(model, glm::radians(70.f), glm::vec3(1.0f, 0.f, 0.f));
    model = glm::translate(model, m_Pos);
    
    Renderer::draw(m_vao, model);
    
    
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
    
    ImGui::Begin("Vars");
    ImGui::SliderFloat("X", &m_Pos.x, -10.0f, 10.0f);
    ImGui::SliderFloat("Y", &m_Pos.y, -10.0f, 10.0f);
    ImGui::SliderFloat("Z", &m_Pos.z, -10.0f, 10.0f);
    ImGui::End();

    
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
