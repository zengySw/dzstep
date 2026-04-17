import React from 'react';
import PricingCard from './PricingCard';

const PricingTable = () => {
  const plans = [
    {
      title: 'Basic',
      price: '2.99',
      color: '#00794b',
      features: [
        { text: 'Sample Text Here', included: true },
        { text: 'Other Text Title', included: false },
        { text: 'Text Space Goes Here', included: false },
        { text: 'Description Space', included: false },
      ]
    },
    {
      title: 'Standard',
      price: '5.99',
      color: '#006ef5',
      isFeatured: true,
      features: [
        { text: 'Sample Text Here', included: true },
        { text: 'Other Text Title', included: true },
        { text: 'Text Space Goes Here', included: true },
        { text: 'Description Space', included: false },
      ]
    },
    {
      title: 'Premium',
      price: '0.99',
      color: '#003366',
      features: [
        { text: 'Sample Text Here', included: true },
        { text: 'Other Text Title', included: true },
        { text: 'Text Space Goes Here', included: true },
        { text: 'Description Space', included: true },
      ]
    }
  ];

  return (
    <div style={{ 
      display: 'flex', 
      gap: '20px', 
      justifyContent: 'center', 
      alignItems: 'center', 
      padding: '50px 20px' 
    }}>
      {plans.map((plan, idx) => (
        <PricingCard key={idx} {...plan} />
      ))}
    </div>
  );
};

export default PricingTable;