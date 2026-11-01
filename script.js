const demoDrivers = [
  { name: "Aman Kumar", vehicle: "Bike", location: "City Centre", distance: 2.0, available: true },
  { name: "Rahul Sharma", vehicle: "Sedan", location: "Bus Stand", distance: 4.5, available: true },
  { name: "Simran Kaur", vehicle: "Auto", location: "Market Road", distance: 1.2, available: true }
];

function bookRide() {
  const passenger = document.getElementById("passenger").value.trim();
  const pickup = document.getElementById("pickup").value.trim();
  const destination = document.getElementById("destination").value.trim();
  const distance = Number(document.getElementById("distance").value);
  const result = document.getElementById("result");

  if (!passenger || !pickup || !destination || !Number.isFinite(distance) || distance <= 0) {
    result.className = "result show";
    result.innerHTML = "Please fill in all fields and enter a trip distance greater than zero.";
    return;
  }

  const driver = demoDrivers.find(d => d.available);
  if (!driver) {
    result.className = "result show";
    result.textContent = "Sorry, no drivers are currently available.";
    return;
  }

  driver.available = false;
  const fare = distance * 12;
  result.className = "result show";
  result.innerHTML = `<strong>✓ Demo ride request confirmed!</strong><br>
    Passenger: ${escapeHTML(passenger)}<br>
    ${escapeHTML(pickup)} → ${escapeHTML(destination)}<br>
    Matched driver: ${driver.name} (${driver.vehicle})<br>
    Estimated fare: ₹${fare.toFixed(2)}<br>
    <small>This is a website demonstration using sample data.</small>`;
}

function escapeHTML(value) {
  return value.replace(/[&<>"']/g, char => ({
    "&": "&amp;", "<": "&lt;", ">": "&gt;", '"': "&quot;", "'": "&#39;"
  }[char]));
}
