#pragma once

class ShaderManager
{
public:
    void  GetDevice(ComPtr<ID3D11Device> device);
    std::pair<ComPtr<ID3D11VertexShader>, ComPtr<ID3DBlob>> GetVSAndVertexShaderCode(const std::wstring& filepath);
    ComPtr<ID3D11PixelShader>                               GetPS(const std::wstring& filepath);

    static ShaderManager& GetInstance()
    {
        static ShaderManager instance;
        return instance;
    }

private:
    ShaderManager() {}
    ~ShaderManager() {
        m_VertexShadersAndShaderCodes.clear();
        m_PixelShaders.clear();
    }

    ComPtr<ID3D11Device> m_Device;
    std::map <std::wstring, std::pair<ComPtr<ID3D11VertexShader>, ComPtr<ID3DBlob>> > m_VertexShadersAndShaderCodes;
    std::map <std::wstring, ComPtr<ID3D11PixelShader>>  m_PixelShaders;
};

#define SHADER_MANAGER ShaderManager::GetInstance()
inline ShaderManager& GetShaderManager() { return ShaderManager::GetInstance(); }
