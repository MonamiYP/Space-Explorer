#include "IndexBuffer.hpp"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count) : m_count(count) {
    glGenBuffers(1, &m_bufferID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer() {
    glDeleteBuffers(1, &m_bufferID);
}

void IndexBuffer::Bind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferID);
}
void IndexBuffer::Unbind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}