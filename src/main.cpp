#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <cmath>

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

float myTurn() {
    std::srand(static_cast<unsigned int>(time(0)));

    std::vector<float> probabilities = {0.008f, 0.02f, 0.05f, 0.1f, 0.222f, 0.60f};

    int randomInt = randomWithProbabilities(probabilities);

    float multi = 0.0f;
    float randomFloat = 0.0f;

    if (randomInt == 0) {
        multi = static_cast<float>(std::rand() % (1000 - 4192 + 1) + 4192) / 100.0f;
        randomFloat = static_cast<float>(std::rand()) / RAND_MAX;
        multi = std::floor((multi + randomFloat) * 100) / 100.0f;
    }
    else if (randomInt == 1) {
        multi = static_cast<float>(std::rand() % (4191 - 867 + 1) + 867) / 100.0f;
        randomFloat = static_cast<float>(std::rand()) / RAND_MAX;
        multi = std::floor((multi + randomFloat) * 100) / 100.0f;
    }
    else if (randomInt == 2) {
        multi = static_cast<float>(std::rand() % (866 - 195 + 1) + 195) / 100.0f;
        randomFloat = static_cast<float>(std::rand()) / RAND_MAX;
        multi = std::floor((multi + randomFloat) * 100) / 100.0f;
    }
    else if (randomInt == 3) {
        multi = static_cast<float>(std::rand() % (194 - 140 + 1) + 140) / 100.0f;
        randomFloat = static_cast<float>(std::rand()) / RAND_MAX;
        multi = std::floor((multi + randomFloat) * 100) / 100.0f;
    }
    else if (randomInt == 4) {
        multi = static_cast<float>(std::rand() % (139 - 124 + 1) + 124) / 100.0f;
        randomFloat = static_cast<float>(std::rand()) / RAND_MAX;
        multi = std::floor((multi + randomFloat) * 100) / 100.0f;
    }
    else if (randomInt == 5) {
        multi = static_cast<float>(std::rand() % (124 - 1 + 1) + 1) / 100.0f;
        randomFloat = static_cast<float>(std::rand()) / RAND_MAX;
        multi = std::floor((multi + randomFloat) * 100) / 100.0f;
    }

    if (multi < 1) {
        multi = multi + 1;
    }

    std::cout << "Random Int: " << randomInt << std::endl;
    std::cout << "Multiplier: " << multi << std::endl;

    return multi;
}

float impossibleProb() {
    std::srand(static_cast<unsigned int>(time(0)));

    std::vector<float> probabilities = {0.008f, 0.02f, 0.05f, 0.1f, 0.222f, 0.60f};

    int randomInt = randomWithProbabilities(probabilities);

    float multi = 0.0f;
    float randomFloat = 0.0f;

    if (randomInt == 0) {
        multi = static_cast<float>(std::rand() % static_cast<int>(std::round((1000 - 41.92) * 100))) / 100 + 41.92;
        randomFloat = static_cast<float>(std::rand()) / RAND_MAX;
        multi = std::floor((multi + randomFloat) * 100) / 100;
    }
    else if (randomInt == 1) {
        multi = static_cast<float>(std::rand() % static_cast<int>(std::round((41.91 - 8.67) * 100))) / 100 + 8.67;
        randomFloat = static_cast<float>(std::rand()) / RAND_MAX;
        multi = std::floor((multi + randomFloat) * 100) / 100;
    }
    else if (randomInt == 2) {
        multi = static_cast<float>(std::rand() % static_cast<int>(std::round((8.66 - 1.95) * 100))) / 100 + 1.95;
        randomFloat = static_cast<float>(std::rand()) / RAND_MAX;
        multi = std::floor((multi + randomFloat) * 100) / 100;
    }
    else if (randomInt == 3) {
        multi = static_cast<float>(std::rand() % static_cast<int>(std::round((1.94 - 1.40) * 100))) / 100 + 1.40;
        randomFloat = static_cast<float>(std::rand()) / RAND_MAX;
        multi = std::floor((multi + randomFloat) * 100) / 100;
    }
    else if (randomInt == 4) {
        multi = static_cast<float>(std::rand() % static_cast<int>(std::round((1.39 - 1.24) * 100))) / 100 + 1.24;
        randomFloat = static_cast<float>(std::rand()) / RAND_MAX;
        multi = std::floor((multi + randomFloat) * 100) / 100;
    }
    else if (randomInt == 5) {
        multi = static_cast<float>(std::rand() % static_cast<int>(std::round((1.24 - 1) * 100))) / 100 + 1.0;
        randomFloat = static_cast<float>(std::rand()) / RAND_MAX;
        multi = std::floor((multi + randomFloat) * 100) / 100;
    }

    std::cout << "Random Int: " << randomInt << std::endl;
    std::cout << "Multiplier: " << multi << std::endl;

    return multi;
}

void startGame(int bet, float multiplicator) {
    multi = myTurn();
    gameStatus = true;

    if (multiplicator <= multi) {
        betWon = (bet * multiplicator) - bet;
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
    GLFWwindow *window = glfwCreateWindow(800, 600, "ImGui Input Probabilistico", nullptr, nullptr);
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
            ImGui::Text("Multiplicador %.2f", multi);
        }
        if (gameStatus && !gameWon) {
            ImGui::Text("Você perdeu %d", bet);
            ImGui::Text("Multiplicador %.2f", multi);
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
