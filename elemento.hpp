#ifndef ELEMENTO_HPP
#define ELEMENTO_HPP

template <class TIPO>
class Elemento {
private:
    Elemento<TIPO>* pProx;
    TIPO* pInfo;

public:
    Elemento() : pProx(nullptr), pInfo(nullptr) {}
    ~Elemento() {
        pProx = nullptr;
        pInfo = nullptr;
    }

    void setProx(Elemento<TIPO>* p) { pProx = p; }
    Elemento<TIPO>* getProx() const { return pProx; }

    void setInfo(TIPO* i) { pInfo = i; }
    TIPO* getInfo() const { return pInfo; }
};

#endif