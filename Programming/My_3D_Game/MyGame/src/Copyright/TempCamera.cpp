/*using namespace glm;

vec3 cameraPos = vec3(0.0f, 0.0f, 3.0f);
vec3 cameraTarget = vec3(0.0f, 0.0f, 0.0f);
vec3 cameraDirection = normalize(cameraPos - cameraTarget);// pointing in reverse direction (out of screen)
vec3 up = vec3(0.0f, 1.0f, 0.0f);
vec3 cameraRight = normalize(cross(up, cameraDirection));
vec3 cameraUp = cross(cameraDirection, cameraRight);
vec3 cameraFront = vec3(0.0f, 0.0f, -1.0f);

void processInput(GLFWwindow *window)
{
	float cameraSpeed = 2.5f * deltaTime;
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		cameraPos += cameraSpeed * cameraFront;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		cameraPos -= cameraSpeed * cameraFront;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		cameraPos -= normalize(cross(cameraFront, cameraUp)) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		cameraPos += normalize(cross(cameraFront, cameraUp)) * cameraSpeed;
}

direction.x = cos(radians(pitch)) * cos(radians(yaw));
direction.y = sin(radians(pitch));
direction.z = cos(radians(pitch)) * sin(radians(yaw));

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	float sensitivity = 0.05;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	if(pitch > 89.0f)
		pitch = 89.0f;
	if(pitch < -89.0f)
		pitch = -89.0f;

	vec3 front;
	front.x = cos(radians(yaw)) * cos(radians(pitch));
	front.y = sin(radians(pitch));
	front.z = sin(radians(yaw)) * cos(radians(pitch));
	cameraFront = normalize(front);
}

float lastX = 400, lastY = 300;

if(pitch > 89.0f)
	pitch = 89.0f;
if(pitch < -89.0f)
	pitch = -89.0f;

vec3 front;
front.x = cos(radians(pitch)) * cos(radians(yaw));
front.y = sin(radians(pitch));
front.z = cos(radians(pitch)) * sin(radians(yaw));
cameraFront = normalize(front);

/*
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

int main()
{
    // render loop
    while (!glfwWindowShouldClose(window))
    {
        // activate shader
        ourShader.use();

        // pass projection matrix to shader (note that in this case it could change every frame)
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        ourShader.setMat4("projection", projection);

        // camera/view transformation
        glm::mat4 view = camera.GetViewMatrix();
        ourShader.setMat4("view", view);

        // render objects
    }
}*/