//
//  MainLayer.cpp
//  CrudeRender
//
//  Created by Hervé Schmit-Veiler on 5/11/20.
//  Copyright © 2020 Hervé Schmit-Veiler. All rights reserved.
//

#include "MainLayer.hpp"

using namespace Crude;

MainLayer::MainLayer()
: Layer("Main0")
{
    
}

void MainLayer::onAttach()
{
    const char* vert =
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
    "}\n";
    
    
    m_Shader = std::make_unique<Crude::Shader>("assets/shadersources/mainShader.vs", "assets/shadersources/mainShader.fs");
    m_Shader->bind();
    
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

    
    
    float vertices[]
    {
        /*100.f, 100.f, 0.0f,
        -100.f, 100.f, 0.0f,
        100.f, -100.f, 0.0f,
        -100.f, -100.f, 0.0f,*/
        
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
    
    static Crude::VertexBuffer vbo(&vertices, sizeof(vertices));
    Crude::VertexBufferLayout layout;
    layout.push<float>(3);
    
    static Crude::IndexBuffer ebo(indices, 6);
    
    //Crude::VertexArray vao;
    m_vao.addVertexBuffer(vbo, layout);
    m_vao.addIndexBuffer(ebo);
    
    m_vao.unbind();
    
    
    cam.setPosition(glm::vec3(0.0f, 0.0f, -3.0f));
    cam.setProjection(-1.f, 1.f, -1.f, 1.f, -1.f, 1.f);
    //cam.setProjection(-720.f/2, 720.f/2, 1280.f/2, -1280.f/2, -1.f, 1.f);
    
    
    //m_Shader = Crude::Shader("assets/shadersources/mainShader.vs", "assets/shadersources/mainShader.fs");
    //m_Shader->bind();
}

void MainLayer::onUpdate()
{
    glClearColor(1.0f, 0.4f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glm::mat4 model(1.0f);
    model = glm::translate(model, m_Pos);
    //testCam->SetPosition(m_Pos);

    
    glm::mat4 viewProjection = cam.getViewProjectionMatrix();//testCam->GetViewProjectionMatrix();//cam.getViewProjectionMatrix();
    
    glm::vec4 testPos = glm::vec4(m_Pos, 1.0f);
    //testPos = projection * view * testPos;
    //testPos = viewProjection * model * testPos;
    //LOG_TRACE("Position: {0}, {1}, {2}", testPos.x, testPos.y, testPos.z);
    
    m_Shader->bind();
    //m_Shader->setMat4("u_MVP",  projection * view * model);
    m_Shader->setMat4("u_MVP",  viewProjection * model);
    m_Shader->setVec4f("u_Colour", 0.5f, 0.5f, 1.0f, 1.0f);
    //m_shader.bind();
    //m_vao.bind();
    m_vao.bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
    
    /*if(Crude::Input::isKeyPressed(CRD_KEY_LEFT_CONTROL))
    {
        LOG_TRACE("0 is pressed!");
    }*/
    //CORE_LOG_TRACE("Yeet, it's updating");
}

void MainLayer::onImGuiRender()
{
    //ImGui::ShowUserGuide();
    //ImGui::ShowDemoWindow();
    ImGui::ShowCrudeDockSpace();
    ImGui::ShowDemoWindow();
    
    ImGui::Begin("Vars");
    ImGui::SliderFloat("X", &m_Pos.x, -10.0f, 10.0f);
    ImGui::SliderFloat("Y", &m_Pos.y, -10.0f, 10.0f);
    ImGui::SliderFloat("Z", &m_Pos.z, -10.0f, 10.0f);
    ImGui::End();
    /*ImGui::Begin("Test1");
     ImGui::End();
     ImGui::Begin("Test2");
     ImGui::End();*/
    
}

void MainLayer::onEvent(Crude::Event& event)
{
    Crude::EventDispatcher dispatcher(event);
    dispatcher.dispatch<Crude::KeyTypedEvent>(BIND_EVENT_FN(MainLayer::onKeyTypedEvent));
}


bool MainLayer::onKeyTypedEvent(Crude::KeyTypedEvent& event)
{
    LOG_TRACE("Key not captured");
    return true;
}
