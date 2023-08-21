#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

static bool gameStatus = false;
static bool gameWon = false;

static int bet = 0;
static float multiplicator = 1.0f;

static float betWon = 0.0f;
static float multi = 0.0f;

int randomWithProbabilities(const std::vector<float>& probs) {
    float totalProb = std::accumulate(probs.begin(), probs.end(), 0.0f);
    float rand = static_cast<float>(std::rand()) / RAND_MAX * totalProb;
    float cumulativeProb = 0.0f;
    for (size_t i = 0; i < probs.size(); i++) {
        cumulativeProb += probs[i];
        if (rand < cumulativeProb) {
            return static_cast<int>(i);
        }
    }
    return static_cast<int>(probs.size() - 1);
}

float gameProbs() {
    std::srand(static_cast<unsigned int>(time(0)));

    std::vector<float> probabilities = {0.03f, 0.1f, 0.87f};

    int randomInt = randomWithProbabilities(probabilities);

    float multi = 0.0f;
    float randomFloat = 0.0f;

    if (randomInt == 0) {
        multi = static_cast<float>(std::rand() % (100 - 8 + 1) + 5);
        randomFloat = static_cast<float>(std::rand()) / RAND_MAX;
        multi = std::floor((multi + randomFloat) * 100) / 100;
    }
    else if (randomInt == 1) {
        multi = static_cast<float>(std::rand() % (6 - 154 + 1) + 154) / 100;
        randomFloat = static_cast<float>(std::rand()) / RAND_MAX;
        multi = std::floor((multi + randomFloat) * 100) / 100;
    }
    else if (randomInt == 2) {
        multi = static_cast<float>(std::rand() % (154 - 100 + 1) + 100) / 100;
        randomFloat = static_cast<float>(std::rand()) / RAND_MAX;
        multi = std::floor((multi + randomFloat) * 100) / 100;
    }

    std::cout << "Random Int: " << randomInt << std::endl;
    std::cout << "Multiplier: " << multi << std::endl;

    return multi;
}

void startGame(int bet, float multiplicator) {
    float multi = gameProbs();
    gameStatus = true;

    if (multiplicator <= multi) {
        betWon = bet * multiplicator;
        gameWon = true;
    }
    else {
        gameWon = false;
    }

}


int main() {
    // Inicialização do GLFW
    if (!glfwInit())
        return 1;

    // Configuração da janela do GLFW
    GLFWwindow *window = glfwCreateWindow(800, 600, "ImGui Input e Cálculo", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // Inicialização do Dear ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // Início da frame do Dear ImGui
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Interface do usuário
        ImGui::Text("Entre com dois números:");
        ImGui::InputInt("Sua aposta", &bet);
        ImGui::InputFloat("Seu Multiplicador", &multiplicator);

        if (ImGui::Button("Apostar"))
            startGame(bet, multiplicator);

        if (gameStatus && gameWon) {
            ImGui::Text("Você ganhou %.2f", betWon);
        }
        if (gameStatus && !gameWon) {
            ImGui::Text("Você perdeu");
        }

        // Renderização da GUI do Dear ImGui
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // Encerramento
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwTerminate();

    return 0;
}
