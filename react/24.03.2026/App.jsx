import React, { useState } from 'react';
import './App.css';

const initialFormData = {
  userId: '',
  password: '',
  name: '',
  address: '',
  country: '',
  zipCode: '',
  email: '',
  sex: '',
  languageEnglish: false,
  languageNonEnglish: false,
  about: ''
};

const App = () => {
  const [formData, setFormData] = useState(initialFormData);

  const handleChange = (event) => {
    const { name, value, type, checked } = event.target;
    setFormData((prev) => ({
      ...prev,
      [name]: type === 'checkbox' ? checked : value
    }));
  };

  const handleSubmit = (event) => {
    event.preventDefault();

    const dataToExport = {
      userId: formData.userId,
      password: formData.password,
      name: formData.name,
      address: formData.address,
      country: formData.country,
      zipCode: formData.zipCode,
      email: formData.email,
      sex: formData.sex,
      language: [
        formData.languageEnglish ? 'English' : null,
        formData.languageNonEnglish ? 'Non English' : null
      ].filter(Boolean),
      about: formData.about
    };

    const json = JSON.stringify(dataToExport, null, 2);
    const blob = new Blob([json], { type: 'application/json' });
    const url = URL.createObjectURL(blob);
    const link = document.createElement('a');

    link.href = url;
    link.download = 'form-data.json';
    document.body.appendChild(link);
    link.click();
    link.remove();
    URL.revokeObjectURL(url);
  };

  return (
    <div className="form-page">
      <form className="registration-form" onSubmit={handleSubmit}>
        <div className="form-row">
          <label htmlFor="userId">User id [5 to 7 characters] :</label>
          <input
            id="userId"
            name="userId"
            type="text"
            value={formData.userId}
            onChange={handleChange}
            minLength={5}
            maxLength={7}
            pattern="[A-Za-z0-9]{5,7}"
            title="Use 5-7 letters or numbers"
            required
          />
        </div>

        <div className="form-row">
          <label htmlFor="password">Password [7 to 12 characters] :</label>
          <input
            id="password"
            name="password"
            type="password"
            value={formData.password}
            onChange={handleChange}
            minLength={7}
            maxLength={12}
            required
          />
        </div>

        <div className="form-row">
          <label htmlFor="name">Name [Alphabates characters] :</label>
          <input
            id="name"
            name="name"
            type="text"
            value={formData.name}
            onChange={handleChange}
            pattern="[A-Za-z ]+"
            title="Use alphabet letters only"
            required
          />
        </div>

        <div className="form-row">
          <label htmlFor="address">Address [alphanumeric characters] :</label>
          <input
            id="address"
            name="address"
            type="text"
            value={formData.address}
            onChange={handleChange}
            pattern="[A-Za-z0-9 ]+"
            title="Use letters and numbers only"
            required
          />
        </div>

        <div className="form-row">
          <label htmlFor="country">Country [Must select a country] :</label>
          <select id="country" name="country" value={formData.country} onChange={handleChange} required>
            <option value="">(Please select a country)</option>
            <option value="Ukraine">Ukraine</option>
            <option value="United States">United States</option>
            <option value="Poland">Poland</option>
            <option value="Germany">Germany</option>
          </select>
        </div>

        <div className="form-row">
          <label htmlFor="zipCode">ZIP Code [alphanumeric characters] :</label>
          <input
            id="zipCode"
            name="zipCode"
            type="text"
            value={formData.zipCode}
            onChange={handleChange}
            pattern="[A-Za-z0-9 ]+"
            title="Use letters and numbers only"
            required
          />
        </div>

        <div className="form-row">
          <label htmlFor="email">Email [Valid email] :</label>
          <input
            id="email"
            name="email"
            type="email"
            value={formData.email}
            onChange={handleChange}
            required
          />
        </div>

        <div className="form-row">
          <span className="row-label">Sex [Select Male or Female] :</span>
          <div className="inline-options">
            <label className="option-chip" htmlFor="male">
              <input
                id="male"
                type="radio"
                name="sex"
                value="Male"
                checked={formData.sex === 'Male'}
                onChange={handleChange}
                required
              />
              Male
            </label>
            <label className="option-chip" htmlFor="female">
              <input
                id="female"
                type="radio"
                name="sex"
                value="Female"
                checked={formData.sex === 'Female'}
                onChange={handleChange}
              />
              Female
            </label>
          </div>
        </div>

        <div className="form-row">
          <span className="row-label">Language [Optional] :</span>
          <div className="inline-options">
            <label className="option-chip" htmlFor="languageEnglish">
              <input
                id="languageEnglish"
                type="checkbox"
                name="languageEnglish"
                checked={formData.languageEnglish}
                onChange={handleChange}
              />
              English
            </label>
            <label className="option-chip" htmlFor="languageNonEnglish">
              <input
                id="languageNonEnglish"
                type="checkbox"
                name="languageNonEnglish"
                checked={formData.languageNonEnglish}
                onChange={handleChange}
              />
              Non English
            </label>
          </div>
        </div>

        <div className="form-row form-row-about">
          <label htmlFor="about">About [Optional] :</label>
          <textarea id="about" name="about" value={formData.about} onChange={handleChange} rows={8} />
        </div>

        <div className="submit-row">
          <button type="submit">Submit</button>
        </div>
      </form>
    </div>
  );
};

export default App;
