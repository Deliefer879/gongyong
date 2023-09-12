#pragma once

class IWindowObserver {
public:
    virtual void OnWindowResize(DWORD newWidth, DWORD newHeight) = 0;
};

class GameWindow
{
public:
    void MakeWindow(std::wstring title, HINSTANCE hInst, DWORD dwWindowWidth, DWORD dwWindowHeight);

    void AddObserver(IWindowObserver* observer) {
        m_Observers.push_back(observer);
    }

    // broadcast window resize event to all observers
    void SetWindowSize(DWORD newWidth, DWORD newHeight) {
        m_WindowWidth = newWidth;
        m_WindowHeight = newHeight;
        NotifyObserver();
    }

    HWND GetWindowHandle() const {
        return m_hWnd; // บนป็
    }
    float GetWindowWidth() const {
        return static_cast<float>(m_WindowWidth);
    }
    float GetWindowHeight() const {
        return static_cast<float>(m_WindowHeight);
    }
    GameWindow();

private:
    void NotifyObserver() {
        for (auto& observer : m_Observers) {
            observer->OnWindowResize(m_WindowWidth, m_WindowHeight);
        }
    }

    std::vector<IWindowObserver*> m_Observers;
    HINSTANCE   m_HInstance;
    HWND        m_hWnd;
    DWORD       m_WindowExStyle;
    DWORD       m_WindowStyle;
    DWORD       m_WindowPosX;
    DWORD       m_WindowPosY;
    DWORD       m_WindowWidth;
    DWORD       m_WindowHeight;
};

