import React, { useEffect, useState } from "react";
import MapView from "../components/MapView";
import CountryStatsPanel from "../components/CountryStatsPanel";
import HistoryPanel from "../components/HistoryPanel";
import HamburgerMenu from "../components/HamburgerMenu";
import Sidebar from "../components/Sidebar";
import { City, CityHistory } from "../data/Cities";

const Home: React.FC = () => {
  // States
  const [totalPop, setTotalPop] = useState(0);
  const [selectedCities, setSelectedCities] = useState<City[]>([]);
  const [history, setHistory] = useState<CityHistory[]>([]);
  const [countryStats, setCountryStats] = useState<Record<string, number>>({});
  const [menuOpen, setMenuOpen] = useState(false);

  // Toggles
  const [showCountryStats, setShowCountryStats] = useState(false);
  const [showHeatmap, setShowHeatmap] = useState(false);
  const [showMarkers, setShowMarkers] = useState(true);

  // History search
  const [searchTerm, setSearchTerm] = useState("");

  // Load total population from API
  useEffect(() => {
    fetch("http://localhost:3000/api/cities")
      .then((res) => res.json())
      .then((data) => {
        if (data.maxAccPop) {
          setTotalPop(data.maxAccPop);
        } else {
          console.error("Unexpected /api/cities response:", data);
        }
      })
      .catch((err) => console.error(err));
  }, []);

  const handleDropCity = () => {
    if (totalPop <= 0) {
      console.error("Total population not loaded yet.");
      return;
    }
    const randomVal = Math.floor(Math.random() * totalPop);
    const url = `http://localhost:3000/api/city?val=${randomVal}`;

    fetch(url)
      .then((res) => res.json())
      .then((city: City) => {
        // Add to selectedCities
        setSelectedCities((prev) => [...prev, city]);

        // Update history with timestamp
        const newEntry: CityHistory = { ...city, date: Date.now() };
        setHistory((prev) => [newEntry, ...prev]);

        // Update country stats
        setCountryStats((prevStats) => {
          const count = prevStats[city.country] || 0;
          return { ...prevStats, [city.country]: count + 1 };
        });
      })
      .catch((err) => console.error(err));
  };

  return (
    <div style={{ width: "100vw", height: "100vh", position: "relative" }}>
      {/* Botón Hamburguesa en la esquina superior izquierda */}
      <div style={{ position: "absolute", top: 10, left: 10, zIndex: 1100 }}>
        <HamburgerMenu onToggle={() => setMenuOpen(!menuOpen)} />
      </div>

      {/* Sidebar con las opciones */}
      <Sidebar isOpen={menuOpen}>
        <button onClick={handleDropCity} style={{ marginBottom: "0.5rem" }}>
          Select a Random Person
        </button>

        <button
          onClick={() => setShowCountryStats(!showCountryStats)}
          style={{ marginBottom: "0.5rem" }}
        >
          {showCountryStats ? "Hide" : "Show"} Country Stats
        </button>

        <button
          onClick={() => setShowHeatmap(!showHeatmap)}
          style={{ marginBottom: "0.5rem" }}
        >
          {showHeatmap ? "Disable Heatmap" : "Enable Heatmap"}
        </button>

        <button
          onClick={() => setShowMarkers(!showMarkers)}
          style={{ marginBottom: "1rem" }}
        >
          {showMarkers ? "Hide Markers" : "Show Markers"}
        </button>

        {/* Búsqueda en el historial (por ciudad) */}
        <input
          type="text"
          placeholder="Search City..."
          value={searchTerm}
          onChange={(e) => setSearchTerm(e.target.value)}
          style={{ width: "100%", marginBottom: "0.5rem" }}
        />
      </Sidebar>

      {/* Panel con las estadísticas por país */}
      <CountryStatsPanel show={showCountryStats} countryStats={countryStats} />

      {/* Historial de selecciones */}
      <HistoryPanel
        history={history}
        showSearch={false} // el input está en el Sidebar
        searchTerm={searchTerm}
        setSearchTerm={setSearchTerm}
      />

      {/* El Mapa principal */}
      <MapView
        selectedCities={selectedCities}
        showHeatmap={showHeatmap}
        showMarkers={showMarkers}
      />
    </div>
  );
};

export default Home;
