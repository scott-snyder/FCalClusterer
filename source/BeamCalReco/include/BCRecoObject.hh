#ifndef BCRECOOBJECT_HH
#define BCRECOOBJECT_HH 1

#include <map>

class BCRecoObject{

public:
  BCRecoObject (bool BshouldHaveCluster, bool BhasRightCluster, 
		double thetaCluster, double phiCluster, double z,
		double energy, int nPads, int side, std::map<int, double> const& clusterPads):
    m_shouldHaveCluster(BshouldHaveCluster),
    m_hasRightCluster(BhasRightCluster),
    m_hasWrongCluster(not m_hasRightCluster),
    m_thetamrad(thetaCluster),
    m_phi(phiCluster),
    m_z(z),
    m_energy(energy),
    m_nPads(nPads),
    m_side(side),
    m_omc(-1),
    m_clusterPads(clusterPads)
  {}

  BCRecoObject (): m_shouldHaveCluster(false), 
		   m_hasRightCluster(false), 
		   m_hasWrongCluster(false), 
		   m_thetamrad(-999), 
		   m_phi(-999),
		   m_energy(0.0),
		   m_nPads(0),
		   m_side(0),
		   m_omc(-1)
  {}

  inline bool shouldHaveCluster() const  { return m_shouldHaveCluster; }
  inline bool hasRightCluster() const  { return m_hasRightCluster; }
  inline bool hasWrongCluster() const  { return m_hasWrongCluster; }
  inline double getThetaRad() const { return m_thetamrad/1000; }
  inline double getThetaMrad() const { return m_thetamrad; }
  inline double getPhi () const { return m_phi; }
  inline double getZ () const { return m_z; }
  inline int getNPads() const { return m_nPads; }
  inline double getEnergy() const { return m_energy; }
  inline int    getSide() const { return m_side; }

  inline void setHasRightCluster(bool b) {
    m_hasRightCluster = b;
    m_hasWrongCluster = !b; }

  inline int  getOMC() const { return m_omc; }
  inline void setOMC(int o) { m_omc = o ; }

private:
  bool m_shouldHaveCluster;
  bool m_hasRightCluster;
  bool m_hasWrongCluster;
  double m_thetamrad;
  double m_phi;
  double m_z=0;
  double m_energy;
  int m_nPads;
  int m_side;
  int m_omc;
  std::map<int, double> m_clusterPads{};

public:
  auto getClusterPads() const -> decltype(m_clusterPads) { return m_clusterPads; }

};

#endif
