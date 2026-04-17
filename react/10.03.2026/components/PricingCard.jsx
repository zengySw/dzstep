import React from 'react';
import './PricingCard.css';

const PricingCard = ({ title, price, color, features, isFeatured }) => {
  return (
    <div className={`pricing-card ${isFeatured ? 'featured' : ''}`}>
      <div className="card-header" style={{ backgroundColor: color }}>
        <h2>{title}</h2>
        <div className="price-badge">${price}</div>
      </div>
      <div className="card-body">
        <ul className="feature-list">
          {features.map((item, index) => (
            <li key={index} className={item.included ? 'included' : 'excluded'}>
              <span className="icon">{item.included ? '✔' : '✖'}</span>
              {item.text}
            </li>
          ))}
        </ul>
      </div>
      <div className="card-footer">
        <button className="select-btn" style={{ backgroundColor: color }}>
          SELECT PACKAGE
        </button>
      </div>
    </div>
  );
};

export default PricingCard;